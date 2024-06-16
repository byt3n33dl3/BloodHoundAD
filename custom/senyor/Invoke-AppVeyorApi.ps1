Function Invoke-AppVeyorApi {

    [CmdletBinding(
        ConfirmImpact = "Low",
        SupportsShouldProcess = $true
    )]
    [OutputType()]

    Param (
        [Parameter(
            Mandatory = $false
        )]
        [HashTable] 
        $Headers = @{},
        
        [Parameter(
            Mandatory = $true
        )]
        [String] 
        $Method,

        [Parameter(
            Mandatory = $true
        )]
        [String] 
        $RestMethod,

        [Parameter()]
        [String] 
        $Body = $null
    )

    Begin {
        # Starting with version 0.2, the Api Token is now stored in the Windows Credential Manager.
        # If the xml file containing the Api Token exists, it is loaded into the Credential Manager, and the xml is deleted.
        # As of 20160630 there have only been 8 downloads of this module from the PSGallery, so this code can be removed with 1.0 release.
        if (Test-Path -Path "$env:APPDATA\PSAppVeyor\Private\ApiToken.xml") {
            $token = (Import-Clixml -Path $env:AppData\PSAppVeyor\Private\ApiToken.xml -ErrorAction Stop).GetNetworkCredential().Password

            Set-AppVeyorApiToken -Token $token -Confirm:$false

            Remove-Item -Path "$env:APPDATA\PSAppVeyor\Private\ApiToken.xml" -Confirm:$false
        }

        try {
            [Void][Windows.Security.Credentials.PasswordVault,Windows.Security.Credentials,ContentType=WindowsRuntime]
            
            $token = (New-Object -TypeName Windows.Security.Credentials.PasswordVault -ErrorAction Stop).Retrieve(
                'https://appveyor.com', 'PSAppVeyor'
            ).Password
        } catch {
            $_
            return
        }

        $Headers.Add(
            'Authorization', "Bearer $token"
        )
        $Headers.Add(
            'Content-type', 'application/json'
        )

        $request = @{
            Headers = $Headers
            Uri = "https://ci.appveyor.com/api/${RestMethod}"
            Method = $Method
            ErrorAction = 'Stop'
        }

        if (-not ([String]::IsNullOrEmpty($Body))) {
            $request.Add(
                'Body', $Body
            )
        }

        try {
            if ($PSCmdlet.ShouldProcess($request)) {
                Invoke-RestMethod @request
            }
        } catch {
            $message = ConvertFrom-Json -InputObject $_.ErrorDetails.Message |
                Select-Object -ExpandProperty message
        
            if ($null -ne $message) {
                Write-Error -Message $message
                return
            } else {
                Write-Error $_
                return
            }
        }
    }

    End {
        Remove-Variable -Name token -Force
        
        [GC]::Collect()
    }
}
