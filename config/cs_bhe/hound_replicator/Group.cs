using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using BloodHound;
using System.Threading.Tasks;

namespace Blake;

public class GroupAce
{
    public string PrincipalSID { get; set; }
    public string PrincipalType { get; set; }
    public string RightName { get; set; }
    public bool IsInherited { get; set; }
}

public class Member
{
    public string ObjectIdentifier { get; set; }
    public string ObjectType { get; set; }
}

public class GroupProperties
{
    public string domain { get; set; }
    public string name { get; set; }
    public string distinguishedname { get; set; }
    public string domainsid { get; set; }
    public bool highvalue { get; set; }
    public string samaccountname { get; set; }
    public string description { get; set; }
    public int whencreated { get; set; }
    public bool admincount { get; set; }
}

public class Group
{
    public GroupProperties Properties { get; set; }
    public List<Member> Members { get; set; }
    public List<GroupAce> Aces { get; set; }
    public string ObjectIdentifier { get; set; }
    public bool IsDeleted { get; set; }
    public bool IsACLProtected { get; set; }
}
