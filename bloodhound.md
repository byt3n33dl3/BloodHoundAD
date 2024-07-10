## Personal GUI Version of BloodHound

<a href="https://github.com/pxcs/BlackMarlinExec/"><p align="center">
<img width="300" height="260" src="src/img/loading_new.gif">
</p></a>

## About Active Directory, [BloodHound](https://book.hacktricks.xyz/windows-hardening/active-directory-methodology/bloodhound)
BloodHound is a tool used to analyze Active Directory environments to identify and visualize potential attack paths and security weaknesses, providing attackers with a clear map of exploitable relationships and privileges within a network.<br>

BloodHound is a monolithic web application composed of an embedded React frontend with [Sigma.js](https://www.sigmajs.org/) and a [Go](https://go.dev/) based REST API backend. It is deployed with a [Postgresql](https://www.postgresql.org/) application database and a [Neo4j](https://neo4j.com/) graph database, and is fed by the [SharpHound](https://github.com/BloodHoundAD/SharpHound) and [AzureHound](https://github.com/BloodHoundAD/AzureHound) data collectors.

## From an Attacker's perspective, BloodHound is advantageous 
because it allows them to efficiently map out an organization's Active Directory structure, identify weak points, and pinpoint high value targets such as users with elevated privileges, thus enabling strategic planning of attacks to escalate privileges and move laterally within the network.<br>

## About BloodHound Enterprise

[BloodHound Enterprise](https://bloodhoundenterprise.io/) is an Attack Path Management solution that continuously maps and quantifies Active Directory Attack Paths. You can remove millions, even billions of Attack Paths within your existing architecture and eliminate the attacker’s easiest, most reliable, and most attractive techniques.

### Downloading BloodHound Binaries
> - Pre Compiled BloodHound binaries can be found [here](https://github.com/BloodHoundAD/BloodHound/releases). 

- The rolling release will always be updated to the most recent source. Tagged releases are considered "stable" but will likely not have new features or fixes.

### Creating example data

> - A sample database generator can be found [here](https://github.com/BloodHoundAD/BloodHound-Tools/tree/master/DBCreator)

- You can create your own example Active Directory environment using [BadBloodHound](https://github.com/davidprowe/BadBlood).

## License

BloodHound uses graph theory to reveal hidden relationships and
attack paths in an Active Directory environment.
Copyright (C) 2016-2023 Specter Ops Inc.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see [@](http://www.gnu.org/licenses/)

## Useful Links

- [BloodHound Slack](https://ghst.ly/BHSlack)
- [Wiki](https://github.com/SpecterOps/BloodHound/wiki)
- [Contributors](./CONTRIBUTORS.md)
- [Docker Compose Example](./examples/docker-compose/README.md)
- [BloodHound Docs](https://support.bloodhoundenterprise.io/)
- [Developer Quick Start Guide](https://github.com/SpecterOps/BloodHound/wiki/Development)
- [Contributing Guide](https://github.com/SpecterOps/BloodHound/wiki/Contributing)

## Thanks to
- [BloodHound](https://github.com/BloodHoundAD/)
- BloodHound Team 
- Azure repo 
- Config in C 
- and [GangstaCrew](https://github.com/GangstaCrew)
