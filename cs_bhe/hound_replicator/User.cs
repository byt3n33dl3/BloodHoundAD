using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Blake;

public class UserAce
{
    public string PrincipalSID { get; set; }
    public string PrincipalType { get; set; }
    public string RightName { get; set; }
    public bool IsInherited { get; set; }
}

public class UserProperties
{
    public string domain { get; set; }
    public string name { get; set; }
    public string distinguishedname { get; set; }
    public string domainsid { get; set; }
    public bool highvalue { get; set; }
    public string samaccountname { get; set; }
    public string description { get; set; }
    public int whencreated { get; set; }
    public bool sensitive { get; set; }
    public bool dontreqpreauth { get; set; }
    public bool passwordnotreqd { get; set; }
    public bool unconstraineddelegation { get; set; }
    public bool pwdneverexpires { get; set; }
    public bool enabled { get; set; }
    public bool trustedtoauth { get; set; }
    public int lastlogon { get; set; }
    public int lastlogontimestamp { get; set; }
    public int pwdlastset { get; set; }
    public List<object> serviceprincipalnames { get; set; }
    public bool hasspn { get; set; }
    public object displayname { get; set; }
    public object email { get; set; }
    public object title { get; set; }
    public object homedirectory { get; set; }
    public object userpassword { get; set; }
    public object unixpassword { get; set; }
    public object unicodepassword { get; set; }
    public object sfupassword { get; set; }
    public object logonscript { get; set; }
    public bool admincount { get; set; }
    public List<object> sidhistory { get; set; }
}

public class User
{
    public UserProperties Properties { get; set; }
    public List<object> AllowedToDelegate { get; set; }
    public string PrimaryGroupSID { get; set; }
    public List<object> HasSIDHistory { get; set; }
    public List<object> SPNTargets { get; set; }
    public List<UserAce> Aces { get; set; }
    public string ObjectIdentifier { get; set; }
    public bool IsDeleted { get; set; }
    public bool IsACLProtected { get; set; }
}
