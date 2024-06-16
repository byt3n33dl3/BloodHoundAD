using System;
using BloodHound.Client;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.DirectoryServices;
using System.DirectoryServices.ActiveDirectory;

namespace Blake;

class ActiveDirectory
{
    // Stolen code from https://www.codeproject.com/Articles/18102/Howto-Almost-Everything-In-Active-Directory-via-C#40

    public void CreateTrust(string sourceForestName, string targetForestName)
    {
        Forest sourceForest = Forest.GetForest(new DirectoryContext(
            DirectoryContextType.Forest, sourceForestName));

        Forest targetForest = Forest.GetForest(new DirectoryContext(
            DirectoryContextType.Forest, targetForestName));

        // create an inbound forest trust

        sourceForest.CreateTrustRelationship(targetForest,
            TrustDirection.Outbound);
    }

    public void CreateGroup(string ouPath, string name)
    {
        if (!DirectoryEntry.Exists("LDAP://CN=" + name + "," + ouPath))
        {
            try
            {
                DirectoryEntry entry = new DirectoryEntry("LDAP://" + ouPath);
                DirectoryEntry group = entry.Children.Add("CN=" + name, "group");
                group.Properties["sAmAccountName"].Value = name;
                group.CommitChanges();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message.ToString());
            }
        }
        else { Console.WriteLine(ouPath + " already exists"); }
    }

    public void AddUserToGroup(string userDn, string groupDn)
    {
        try
        {
            DirectoryEntry dirEntry = new DirectoryEntry("LDAP://" + groupDn);
            dirEntry.Properties["member"].Add(userDn);
            dirEntry.CommitChanges();
            dirEntry.Close();
        }
        catch (System.DirectoryServices.DirectoryServicesCOMException E)
        {
            //doSomething with E.Message.ToString();

        }
    }

    public string CreateUserAccount(string ldapPath, string userName, string userPassword)
    {
        string oGUID = string.Empty;
        try
        {
            string connectionPrefix = "LDAP://" + ldapPath;
            DirectoryEntry dirEntry = new DirectoryEntry(connectionPrefix);
            DirectoryEntry newUser = dirEntry.Children.Add
                ("CN=" + userName, "user");
            newUser.Properties["samAccountName"].Value = userName;
            newUser.CommitChanges();
            oGUID = newUser.Guid.ToString();

            newUser.Invoke("SetPassword", new object[] { userPassword });
            newUser.CommitChanges();
            dirEntry.Close();
            newUser.Close();
        }
        catch (System.DirectoryServices.DirectoryServicesCOMException E)
        {
            //DoSomethingwith --> E.Message.ToString();

        }
        return oGUID;
    }

    public void DisableUserAccount(string userDn)
    {
        try
        {
            DirectoryEntry user = new DirectoryEntry(userDn);
            int val = (int)user.Properties["0.0.0.0"].Value;
            user.Properties["0.0.0.0"].Value = val | 0x2;
            //ADS_UF_ACCOUNTDISABLE;

            user.CommitChanges();
            user.Close();
        }
        catch (System.DirectoryServices.DirectoryServicesCOMException E)
        {
            //DoSomethingWith --> E.Message.ToString();

        }
    }


}
