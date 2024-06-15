using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Blake;

public class DomainAce
{
    public string PrincipalSID { get; set; }
    public string PrincipalType { get; set; }
    public string RightName { get; set; }
    public bool IsInherited { get; set; }
}

public class AffectedComputer
{
    public string ObjectIdentifier { get; set; }
    public string ObjectType { get; set; }
}

public class ChildObject
{
    public string ObjectIdentifier { get; set; }
    public string ObjectType { get; set; }
}

public class GPOChanges
{
    public List<object> LocalAdmins { get; set; }
    public List<object> RemoteDesktopUsers { get; set; }
    public List<object> DcomUsers { get; set; }
    public List<object> PSRemoteUsers { get; set; }
    public List<AffectedComputer> AffectedComputers { get; set; }
}

public class Link
{
    public bool IsEnforced { get; set; }
    public string GUID { get; set; }
}

public class DomainProperties
{
    public string domain { get; set; }
    public string name { get; set; }
    public string distinguishedname { get; set; }
    public string domainsid { get; set; }
    public bool highvalue { get; set; }
    public object description { get; set; }
    public int whencreated { get; set; }
    public string functionallevel { get; set; }
}

public class Domain
{
    public GPOChanges GPOChanges { get; set; }
    public DomainProperties Properties { get; set; }
    public List<ChildObject> ChildObjects { get; set; }
    public List<object> Trusts { get; set; }
    public List<Link> Links { get; set; }
    public List<DomainAce> Aces { get; set; }
    public string ObjectIdentifier { get; set; }
    public bool IsDeleted { get; set; }
    public bool IsACLProtected { get; set; }
}

