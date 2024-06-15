using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Blake;

public class OrganizationalUnitAce
{
    public string PrincipalSID { get; set; }
    public string PrincipalType { get; set; }
    public string RightName { get; set; }
    public bool IsInherited { get; set; }
}

public class OrganizationalUnitChildObject
{
    public string ObjectIdentifier { get; set; }
    public string ObjectType { get; set; }
}

public class OrganizationalUnitGPOChanges
{
    public List<object> LocalAdmins { get; set; }
    public List<object> RemoteDesktopUsers { get; set; }
    public List<object> DcomUsers { get; set; }
    public List<object> PSRemoteUsers { get; set; }
    public List<object> AffectedComputers { get; set; }
}

public class OrganizationalUnitProperties
{
    public string domain { get; set; }
    public string name { get; set; }
    public string distinguishedname { get; set; }
    public string domainsid { get; set; }
    public bool highvalue { get; set; }
    public object description { get; set; }
    public int whencreated { get; set; }
    public bool blocksinheritance { get; set; }
}

public class OrganizationalUnit
{
    public OrganizationalUnitGPOChanges GPOChanges { get; set; }
    public OrganizationalUnitProperties Properties { get; set; }
    public List<object> Links { get; set; }
    public List<OrganizationalUnitChildObject> ChildObjects { get; set; }
    public List<OrganizationalUnitAce> Aces { get; set; }
    public string ObjectIdentifier { get; set; }
    public bool IsDeleted { get; set; }
    public bool IsACLProtected { get; set; }
}
