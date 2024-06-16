Function Get-AppVeyorProject {
    
    [CmdletBinding()]
    [OutputType(
        [AppVeyorProject]
    )]

    Param (
        [Parameter(
            Mandatory = $true,
            ValueFromPipelineByPropertyName = $true
        )]
        [String]
        $AccountName,

        [Parameter(
            Mandatory = $true,
            ValueFromPipelineByPropertyName = $true
        )]
        [String]
        $ProjectName
    )

    Process {
        [AppVeyorProject]::new(
            (Invoke-AppVeyorApi -Method 'GET' -RestMethod "projects/${AccountName}/${ProjectName}" |
                Select-Object -ExpandProperty project)
        )
    }
}
