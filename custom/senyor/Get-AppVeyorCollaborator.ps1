Function Get-AppVeyorCollaborator {

    [CmdletBinding()]
    [OutputType(
        [AppVeyorUser]
    )]

    Param (
        [Parameter(
            ValueFromPipeline = $true,
            ValueFromPipelineByPropertyName = $true
        )]
        [Int[]]
        $UserId
    )

    Process {
        if ($null -ne $UserId) {
            foreach ($item in $UserId) {
                [AppVeyorUser]::new(
                    (Invoke-AppVeyorApi -Method 'Get' -RestMethod "collaborators/${item}")
                )
            }
        } else {
            foreach ($result in (Invoke-AppVeyorApi -Method 'Get' -RestMethod 'collaborators')) {
                [AppVeyorUser]::new(
                    $result
                )
            }
        }
    }
}
