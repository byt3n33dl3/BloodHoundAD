using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Blake;

public class BloodHoundData
{
    public List<Computer> computers { get; set; }
    public List<Container> containers { get; set; }
    public List<Domain> domains { get; set; }
    public List<GroupPolicy> groupPolicies { get; set; }
    public List<Group> groups { get; set; }
    public List<OrganizationalUnit> organizationalUnits { get; set; }
    public List<User> users { get; set; }

    public BloodHoundData(List<Computer> computerList, List<Container> containerList, List<Domain> domainList, List<GroupPolicy> groupPolicyList, List<Group> groupList, List<OrganizationalUnit> organizationalUnitList, List<User> userList)
    {
        computers = computerList;
        containers = containerList;
        domains = domainList;
        groupPolicies = groupPolicyList;
        groups = groupList;
        organizationalUnits = organizationalUnitList;
        users = userList;
    }
}
