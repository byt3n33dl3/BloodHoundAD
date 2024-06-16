Function Get-AppVeyorEnvironment {

    [CmdletBinding()]
    [OutputType(
        [AppVeyorEnvironment]
    )]

    Param (
        [Parameter(
            ValueFromPipelineByPropertyName = $true
        )]
        [Int]
        $DeploymentEnvironmentID = $null
    )

    Process {
        $restMethod = "environments"
        if ($null -ne $PSCmdlet.DeploymentEnvironmentId) {
            $restMethod += "/${DeploymentEnvironmentId}/settings"
        }

        [AppVeyorEnvironment]::new(
            (Invoke-AppVeyorApi -Method 'GET' -RestMethod $restMethod)
        )
    }
}
