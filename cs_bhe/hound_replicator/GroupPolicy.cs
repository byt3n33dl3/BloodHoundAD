using System;
using System.Collections.Generic;
using System.Linq;
using BloodHound;
using System.Text;
using System.Threading.Tasks;

namespace Blake;

public class GroupPolicyAce
{
    public string PrincipalSID { get; set; }
    public string PrincipalType { get; set; }
    public string RightName { get; set; }
    public bool IsInherited { get; set; }
}

public class GroupPolicyProperties
{
    public string domain { get; set; }
    public string name { get; set; }
    public string distinguishedname { get; set; }
    public string domainsid { get; set; }
    public bool highvalue { get; set; }
    public object description { get; set; }
    public int whencreated { get; set; }
    public string gpcpath { get; set; }
}

public class GroupPolicy
{
    public GroupPolicyProperties Properties { get; set; }
    public List<GroupPolicyAce> Aces { get; set; }
    public string ObjectIdentifier { get; set; }
    public bool IsDeleted { get; set; }
    public bool IsACLProtected { get; set; }
}
