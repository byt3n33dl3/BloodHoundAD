Function Get-AppVeyorBuild {
    
    [CmdletBinding(
        DefaultParameterSetName = '__AllParameterSets'
    )]
    [OutputType(
        [AppVeyorBuild]
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
        $ProjectName,

        [Parameter(
            ParameterSetName = 'Branch',
            ValueFromPipelineByPropertyName = $true
        )]
        [Alias(
            'RepositoryBranch'
        )]
        [String]
        $BuildBranch,

        [Parameter(
            ParameterSetName = 'Version',
            ValueFromPipeline = $true
        )]
        [Version]
        $BuildVersion
    )

    Process {
        switch ($PSCmdlet.ParameterSetName) {
            'Branch' {
                $restMethod = "projects/${AccountName}/${ProjectName}/branch/${BuildBranch}"
            }
            'Version' {
                $restMethod = "projects/${AccountName}/${ProjectName}/build/${BuildVersion}"
            }
            default {
                $restMethod = "projects/${AccountName}/${ProjectName}"
            }
        }

        [AppVeyorBuild]::new(
            (Invoke-AppVeyorApi -Method 'GET' -RestMethod $restMethod |
                Select-Object -ExpandProperty build)
        )
    }
}
