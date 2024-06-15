using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Blake;

// Root myDeserializedClass = JsonConvert.DeserializeObject<Root>(myJsonResponse);
public class ComputerAce
{
    public string PrincipalSID { get; set; }
    public string PrincipalType { get; set; }
    public string RightName { get; set; }
    public bool IsInherited { get; set; }
}

public class DcomUsers
{
    public List<object> Results { get; set; }
    public bool Collected { get; set; }
    public object FailureReason { get; set; }
}

public class LocalAdmins
{
    public List<object> Results { get; set; }
    public bool Collected { get; set; }
    public object FailureReason { get; set; }
}

public class PrivilegedSessions
{
    public List<object> Results { get; set; }
    public bool Collected { get; set; }
    public object FailureReason { get; set; }
}

public class ComputerProperties
{
    public string domain { get; set; }
    public string name { get; set; }
    public string distinguishedname { get; set; }
    public string domainsid { get; set; }
    public bool highvalue { get; set; }
    public string samaccountname { get; set; }
    public bool haslaps { get; set; }
    public object description { get; set; }
    public int whencreated { get; set; }
    public bool enabled { get; set; }
    public bool unconstraineddelegation { get; set; }
    public bool trustedtoauth { get; set; }
    public int lastlogon { get; set; }
    public int lastlogontimestamp { get; set; }
    public int pwdlastset { get; set; }
    public List<string> serviceprincipalnames { get; set; }
    public string operatingsystem { get; set; }
    public List<object> sidhistory { get; set; }
}

public class PSRemoteUsers
{
    public List<object> Results { get; set; }
    public bool Collected { get; set; }
    public object FailureReason { get; set; }
}

public class RegistrySessions
{
    public List<object> Results { get; set; }
    public bool Collected { get; set; }
    public object FailureReason { get; set; }
}

public class RemoteDesktopUsers
{
    public List<object> Results { get; set; }
    public bool Collected { get; set; }
    public object FailureReason { get; set; }
}

public class Sessions
{
    public List<object> Results { get; set; }
    public bool Collected { get; set; }
    public object FailureReason { get; set; }
}

public class Computer
{
    public ComputerProperties Properties { get; set; }
    public string PrimaryGroupSID { get; set; }
    public List<object> AllowedToDelegate { get; set; }
    public List<object> AllowedToAct { get; set; }
    public List<object> HasSIDHistory { get; set; }
    public Sessions Sessions { get; set; }
    public PrivilegedSessions PrivilegedSessions { get; set; }
    public RegistrySessions RegistrySessions { get; set; }
    public LocalAdmins LocalAdmins { get; set; }
    public RemoteDesktopUsers RemoteDesktopUsers { get; set; }
    public DcomUsers DcomUsers { get; set; }
    public PSRemoteUsers PSRemoteUsers { get; set; }
    public object Status { get; set; }
    public List<ComputerAce> Aces { get; set; }
    public string ObjectIdentifier { get; set; }
    public bool IsDeleted { get; set; }
    public bool IsACLProtected { get; set; }
}
