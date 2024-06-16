# https://www.appveyor.com/docs/api/

#region Classes

Class AppVeyorProject {
    [Int]$ProjectId
    [Int]$AccountId
    [String]$AccountName
    [AppVeyorBuild[]]$Builds
    [String]$Name
    [String]$Slug
    [AppVeyorProjectRepositoryType]$RepositoryType
    [String]$RepositoryScm
    [String]$RepositoryName
    [String]$RepositoryBranch
    [Bool]$IsPrivate
    [Bool]$SkipBranchesWithoutAppVeyorYml
    [Bool]$EnableSecureVariablesInPullRequests
    [Bool]$EnableDeploymentInPullRequests
    [Bool]$AlwaysBuildClosedPullRequests
    [Bool]$RollingBuilds
    [AppVeyorNuGetFeed]$NuGetFeed
    [AppVeyorSecurityDescriptor]$SecurityDescriptor
    [Nullable[DateTime]]$Created
    [Nullable[DateTime]]$Updated

    AppVeyorProject([Object]$object) {
        $this.ProjectId = $object.projectId
        $this.AccountId = $object.accountId
        $this.AccountName = $object.accountName
        $this.Builds = $object.builds
        $this.Name = $object.name
        $this.Slug = $object.slug
        $this.RepositoryType = $object.repositoryType
        $this.RepositoryScm = $object.repositoryScm
        $this.RepositoryName = $object.repositoryName
        $this.RepositoryBranch = $object.repositoryBranch
        $this.IsPrivate = $object.isPrivate
        $this.SkipBranchesWithoutAppVeyorYml = $object.skipBranchesWithoutAppveyorYml
        $this.EnableSecureVariablesInPullRequests = $object.enableSecureVariablesInPullRequests
        $this.EnableDeploymentInPullRequests = $object.enableDeploymentInPullRequests
        $this.AlwaysBuildClosedPullRequests = $object.alwaysBuildClosedPullRequests
        $this.RollingBuilds = $object.rollingBuilds
        $this.NuGetFeed = $object.nuGetFeed
        $this.SecurityDescriptor = $object.securityDescriptor
        $this.Created = $object.created
        $this.Updated = $object.updated
    }
}

Class AppVeyorBuild {
    [Int]$BuildId
    [AppVeyorJob[]]$Jobs
    [Int]$BuildNumber
    [Version]$Version
    [String]$Message
    [String]$MessageExtended
    [String]$Branch
    [String]$CommitId
    [String]$AuthorName
    [String]$AuthorUserName
    [String]$CommitterName
    [String]$CommitterUserName
    [Nullable[DateTime]]$Committed
    [Object[]]$Messages
    [String]$Status
    [Nullable[DateTime]]$Started
    [Nullable[DateTime]]$Finished
    [Nullable[DateTime]]$Created
    [Nullable[DateTime]]$Updated

    AppVeyorBuild([Object]$object) {
        $this.BuildId = $object.buildId
        $this.Jobs = $object.jobs
        $this.BuildNumber = $object.buildNumber
        $this.Version = $object.version
        $this.Message = $object.message
        $this.MessageExtended = $object.messageExtended
        $this.Branch = $object.branch
        $this.CommitId = $object.commitId
        $this.AuthorName = $object.authorName
        $this.AuthorUserName = $object.authorUsername
        $this.CommitterName = $object.committerName
        $this.CommitterUserName = $object.committerUsername
        $this.Committed = $object.committed
        $this.Messages = $this.messages
        $this.Status = $object.status
        $this.Started = $object.started
        $this.Finished = $object.finished
        $this.Created = $object.created
        $this.Updated = $object.updated
    }
}

Class AppVeyorProjectSetting : AppVeyorProject {
    [String]$VersionFormat
    [Int]$NextBuildNumber
    [String]$WebhookId
    [Uri]$WebhookUrl
    [AppVeyorConfiguration]$Configuration
    [Object[]]$Tags

    AppVeyorProjectSetting([Object]$object) : Base([Object]$object) {
        $this.VersionFormat = $object.versionFormat
        $This.NextBuildNumber = $object.nextBuildNumber
        $this.WebhookId = $object.webhookId
        $this.WebhookUrl = $object.webhookUrl
        $this.Configuration = $object.configuration
        $this.Tags = $object.tags
    }
}

Class AppVeyorConfiguration {
    [Bool]$DoNotIncrementBuildNumberOnPullRequests
    [Object[]]$InitScripts
    [Object[]]$IncludeBranches
    [Object[]]$ExcludeBranches
    [Bool]$SkipTags
    [Bool]$SkipNonTags
    [Object[]]$SkipCommitsFiles
    [Object[]]$OnlyCommitsFiles
    [Object[]]$CloneScripts
    [Object[]]$OnBuildSuccessScripts
    [Object[]]$OnBuildErrorScripts
    [Object[]]$OnBuildFinishScripts
    [Bool]$PatchAssemblyInfo
    [Object]$AssemblyInfoFile
    [Object]$AssemblyVersionFormat
    [Object]$AssemblyFileVersionFormat
    [Object]$AssemblyInformationalVersionFormat
    [Object[]]$OperatingSystem
    [Object[]]$Services
    [Bool]$ShallowClone
    [Bool]$ForceHttpsClone
    [Object[]]$EnvironmentVariables
    [Object[]]$EnvironmentVariablesMatrix
    [Object[]]$InstallScripts
    [Object[]]$HostEntries
    [Object[]]$CacheEntries
    [Bool]$ConfigrueNuGetProjectSource
    [Bool]$ConfigureNuGetAccountSource
    [Bool]$DisableNuGetPublishOnPullRequests
    [String]$BuildMode
    [Object[]]$Platform
    [Object[]]$Configuration
    [Bool]$PackageWebApplicationProjects
    [Bool]$PackageWebApplicationProjectsXCopy
    [Bool]$PackageAzureCloudServiceProjects
    [Bool]$PackageNuGetProjects
    [Bool]$PackageNuGetSymbols
    [Bool]$IncludeNuGetReferences
    [Bool]$MSBuildInParallel
    [String]$MSBuildVerbosity
    [Object[]]$BuildScripts
    [Object[]]$BeforeBuildScripts
    [Object[]]$AfterBuildScripts
    [String]$TestMode
    [Object[]]$TestAssemblies
    [Object[]]$TestCategories
    [Object[]]$TestCategoriesMatrix
    [Object[]]$TestScripts
    [Object[]]$BeforeTestScripts
    [Object[]]$AfterTestScripts
    [String]$DeployMode
    [Object[]]$Deployments
    [Object[]]$DeployScripts
    [Object[]]$BeforeDeployScripts
    [Object[]]$AfterDeployScripts
    [Bool]$XamarianRegisterAndroidProduct
    [Bool]$XamarianRegisterIosProduct
    [Bool]$MatrixFastFinish
    [Object[]]$MatrixAllowFailures
    [Object[]]$Artifacts
    [Object[]]$Notifications

    AppVeyorConfiguration([Object]$object) {
        $this.DoNotIncrementBuildNumberOnPullRequests = $object.DoNotIncrementBuildNumberOnPullRequests
        $this.InitScripts = $object.initScripts
        $this.IncludeBranches = $object.includeBranches
        $this.ExcludeBranches = $object.ExcludeBranches
        $this.OnBuildSuccessScripts = $object.onBuildSuccessScripts
        $this.OnBuildErrorScripts = $object.onBuildErrorScripts
        $this.OnBuildFinishScripts = $object.onBuildFinishScripts
        $this.PatchAssemblyInfo = $object.patchAssemblyInfo
        $this.AssemblyInfoFile = $object.assemblyInfoFile
        $this.AssemblyFileVersionFormat = $object.assemblyFileVersionFormat
        $this.AssemblyInformationalVersionFormat = $object.assemblyInformationalVersionFormat
        $this.OperatingSystem = $object.operatingSystem
        $this.Services = $object.services
        $this.ShallowClone = $object.shallowClone
        $this.ForceHttpsClone = $object.forceHttpsClone
        $this.EnvironmentVariables = $object.environmentVariables
        $this.EnvironmentVariablesMatrix = $object.environmentVariablesMatrix
        $this.InstallScripts = $object.installScripts
        $this.HostEntries = $object.hostEntries
        $this.CacheEntries = $object.cacheEntries
        $this.ConfigrueNuGetProjectSource = $object.configureNuGetProjectSource
        $this.ConfigureNuGetAccountSource = $object.configureNuGetAccountSource
        $this.DisableNuGetPublishOnPullRequests = $object.disableNuGetPublishOnPullRequests
        $this.BuildMode = $object.buildMode
        $this.Platform = $object.platform
        $this.Configuration = $object.configuration
        $this.PackageWebApplicationProjects = $object.packageWebApplicationProjects
        $this.PackageWebApplicationProjectsXCopy = $object.packageWebApplicationProjectsXCopy
        $this.PackageAzureCloudServiceProjects = $object.packageAzureCloudServiceProjects
        $this.PackageNuGetProjects = $object.packageNuGetProjects
        $this.PackageNuGetSymbols = $object.packageNuGetSymbols
        $this.IncludeNuGetReferences = $object.includeNuGetReferences
        $this.MSBuildInParallel = $object.msBuildInParallel
        $this.MSBuildVerbosity = $object.msBuildVerbosity
        $this.BuildScripts = $object.buildScripts
        $this.BeforeBuildScripts = $object.beforeBuildScripts
        $this.AfterBuildScripts = $object.afterBuildScripts
        $this.TestMode = $object.testMode
        $this.TestAssemblies = $object.testAssemblies
        $this.TestCategories = $object.testCategories
        $this.TestCategoriesMatrix = $object.testCategoriesMatrix
        $this.TestScripts = $object.testScripts
        $this.BeforeTestScripts = $object.beforeTestScripts
        $this.AfterTestScripts = $object.afterTestScripts
        $this.DeployMode = $object.deployMode
        $this.Deployments = $object.deployments
        $this.BeforeDeployScripts = $object.beforeDeployScripts
        $this.AfterDeployScripts = $object.afterDeployScripts
        $this.XamarianRegisterAndroidProduct = $object.xamarianRegisterAndroidProduct
        $this.XamarianRegisterIosProduct = $object.xamarianRegisterIosProduct
        $this.MatrixFastFinish = $object.matrixFastFinish
        $this.MatrixAllowFailures = $object.matrixAllowFailures
        $this.Artifacts = $object.atrifacts
        $this.Notifications = $object.notifications
    }

    AppVeyorConfiguration() { }
}

Class AppVeyorJob {
    [String]$JobId
    [String]$Name
    [Bool]$AllowFailure
    [Int]$MessagesCount
    [Int]$CompilationMessagesCount
    [Int]$CompilationErrorsCount
    [Int]$CompilationWarningsCount
    [Int]$TestsCount
    [Int]$PassedTestsCount
    [Int]$FailedTestsCount
    [Int]$ArtifactsCount
    [String]$Status
    [Nullable[DateTime]]$Started
    [Nullable[DateTime]]$Finished
    [Nullable[DateTime]]$Created
    [Nullable[DateTime]]$Updated

    AppVeyorJob([Object]$object) {
        $this.JobId = $object.jobId
        $this.Name = $object.name
        $this.AllowFailure = $object.allowFailure
        $this.MessagesCount = $object.messagesCount
        $this.CompilationMessagesCount = $object.compilationMessagesCount
        $this.CompilationErrorsCount = $object.compilationErrorsCount
        $this.CompilationWarningsCount = $object.compilationWarningsCount
        $this.TestsCount = $object.testsCount
        $this.PassedTestsCount = $object.passedTestsCount
        $this.FailedTestsCount = $object.failedTestsCount
        $this.ArtifactsCount = $object.artifactsCount
        $this.Status = $object.status
        $this.Started = $object.started
        $this.Finished = $object.finished
        $this.Created = $object.created
        $this.Updated = $object.updated
    }
}

Class AppVeyorNuGetFeed {
    [String]$Id
    [String]$Name
    [Bool]$PublishingEnabled
    [DateTime]$Created

    AppVeyorNuGetFeed([Object]$object) {
        $this.Id = $object.id
        $this.Name = $object.name
        $this.PublishingEnabled = $object.publishingEnabled
        $this.Created = $object.created
    }
}

Class AppVeyorSecurityDescriptor {
    [AppVeyorAccessRightsDefinition[]]$AccessRightDefinitions
    [AppVeyorRoleAce[]]$RoleAces

    AppVeyorSecurityDescriptor([Object]$object) {
        $this.AccessRightDefinitions = $object.accessRightDefinitions
        $this.RoleAces = $object.roleAces
    }
}

Class AppVeyorRoleAce {
    [Int]$RoleId
    [String]$Name
    [Bool]$IsAdmin
    [AppVeyorAccessRight[]]$AccessRights

    AppVeyorRoleAce([Object]$object) {
        $this.RoleId = $object.roleId
        $this.Name = $object.name
        $this.IsAdmin = $object.isAdmin
        $this.AccessRights = $object.accessRights
    }
}

Class AppVeyorAccessRightsDefinition {
    [String]$Name
    [String]$Description

    AppVeyorAccessRightsDefinition([Object]$object) {
        $this.Name = $object.name
        $this.Description = $object.description
    }
}

Class AppVeyorAccessRight {
    [String]$Name
    [Bool]$Allowed

    AppVeyorAccessRight([Object]$object) {
        $this.Name = $object.name
        $this.Allowed = $object.allowed
    }
}

Class AppVeyorEnvironment {
    [Int]$DeploymentEnvironmentId
    [String]$Name
    [String]$Provider
    [String]$EnvironmentAccessKey
    [AppVeyorEnvironmentSetting[]]$Settings
    [Nullable[DateTime]]$Created
    [Nullable[DateTime]]$Updated

    AppVeyorEnvironment([Object]$object) {
        $this.DeploymentEnvironmentId = $object.deploymentEnvironmentId
        $this.Name = $object.name
        $this.Provider = $object.provider
        $this.EnvironmentAccessKey = $object.environmentAccessKey
        $this.Settings = $object.settings
        $this.Created = $object.created
        $this.Updated = $object.updated
    }
}

Class AppVeyorEnvironmentSetting {
    [AppVeyorProviderSetting[]]$ProviderSettings
    [Object[]]$EnvironmentVairables

    AppVeyorEnvironmentSetting([Object]$object) {
        $this.ProviderSettings = $object.providerSettings
        $this.EnvironmentVariables = $object.environmentVariables
    }
}

Class AppVeyorProviderSetting {
    [String]$Name
    [AppVeyourProviderSettingValue]$Value

    AppVeyorProviderSetting([Object]$object) {
        $this.Name = $object.name
        $this.Value = $object.value  
    }
}

Class AppVeyourProviderSettingValue {
    [Bool]$IsEncrypted
    [String]$Value

    AppVeyourProviderSettingValue([Object]$object) {
        $this.IsEncrypted = $object.isEncrypted
        $this.Value = $object.value
    }
}

Class AppVeyorUser {
    [Int]$AccountId
    [String]$AccountName
    [Bool]$IsOwner
    [Bool]$IsCollaborator
    [Int]$UserId
    [String]$FullName
    [String]$Email
    [Int]$RoleId
    [String]$RoleName
    [AppVeyorUserRole[]]$Roles
    [String]$SuccessfulBuildNotification
    [String]$FailedBuildNotification
    [Bool]$NotifyWhenBuildStatusChangedOnly
    [Nullable[DateTime]]$Created
    [Nullable[DateTime]]$Updated

    AppVeyorUser([Object]$object) {
        $this.AccountId = $object.accountId
        $this.AccountName = $object.accountName
        $this.IsOwner = $object.isOwner
        $this.IsCollaborator = $object.isCollaborator
        $this.UserId = $object.userId
        $this.FullName = $object.fullName
        $this.Email = $object.email
        $this.RoleId = $object.roleId
        $this.RoleName = $object.roleName
        $this.SuccessfulBuildNotification = $object.successfulBuildNotification
        $this.FailedBuildNotification = $object.FailedBuildNotification
        $this.NotifyWhenBuildStatusChangedOnly = $object.notifyWhenBuildStatusChangedOnly
        $this.Created = $object.created
        $this.Updated = $object.updated

        $this.Roles = $this.GetUserRoles()
    }

    [AppVeyorUserRole[]] GetUserRoles() {
        return Invoke-AppVeyorApi -Method 'GET' -RestMethod ('users/{0}' -f $this.UserId) |
            Select-Object -ExpandProperty 'roles'
    }
}

Class AppVeyorUserRole {
    [Int]$RoleId
    [String]$Name
    [Bool]$IsSystem
    [Nullable[DateTime]]$Created
    [AppVeyorUserGroup[]]$Groups

    AppVeyorUserRole([Object]$object) {
        $this.RoleId = $object.roleId
        $this.Name = $object.name
        $this.IsSystem = $object.isSystem
        $this.Created = $object.created
        $this.Groups = $object.groups
    }

    AppVeyorUserRole([Object]$object, [Switch]$includeGroups) {
        $this.RoleId = $object.roleId
        $this.Name = $object.name
        $this.IsSystem = $object.isSystem
        $this.Created = $object.created
        $this.Groups = $this.GetUserGroups()
    }

    [AppVeyorUserGroup[]] GetUserGroups() {
        return Invoke-AppVeyorApi -Method 'GET' -RestMethod ('roles/{0}' -f $this.RoleId) |
            Select-Object -ExpandProperty 'groups'
    }
}

Class AppVeyorUserGroup {
    [String]$Name
    [AppVeyorUserGroupPermission[]]$Permissions

    AppVeyorUserGroup([Object]$object) {
        $this.Name = $object.name
        $this.Permissions = $object.permissions
    }
}

Class AppVeyorUserGroupPermission {
    [String]$Name
    [String]$Description
    [Bool]$Allowed

    AppVeyorUserGroupPermission([Object]$object) {
        $this.Name = $object.name
        $this.Description = $object.description
        $this.Allowed = $object.allowed
    }
}

#endregion Classes

#region Enums

Enum AppVeyorProjectRepositoryType {
    GitHub
    BitBucket
    VSO
    GitLab
    Kiln
    Stash
    GitHubMercurial
    SubVersion
}

#endregion Enums
