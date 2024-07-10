// Copyright (C) 2022 Specter Ops, Inc.
//
// This file is part of AzureHound.
//
// AzureHound is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// AzureHound is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

package azure

import "strings"

// Mapped according to https://learn.microsoft.com/en-us/rest/api/containerregistry/registries/get?tabs=HTTP#registry
type ContainerRegistry struct {
	Entity

	Identity ManagedIdentity   `json:"identity,omitempty"`
	Location string            `json:"location,omitempty"`
	Name     string            `json:"name,omitempty"`
	Tags     map[string]string `json:"tags,omitempty"`
	Type     string            `json:"type,omitempty"`
}

func (s ContainerRegistry) ResourceGroupName() string {
	parts := strings.Split(s.Id, "/")
	if len(parts) > 4 {
		return parts[4]
	} else {
		return ""
	}
}

func (s ContainerRegistry) ResourceGroupId() string {
	parts := strings.Split(s.Id, "/")
	if len(parts) > 5 {
		return strings.Join(parts[:5], "/")
	} else {
		return ""
	}
}

type ContainerRegistryList struct {
	NextLink string              `json:"nextLink,omitempty"` // The URL to use for getting the next set of values.
	Value    []ContainerRegistry `json:"value"`              // A list of container registries.
}

type ContainerRegistryResult struct {
	SubscriptionId string
	Error          error
	Ok             ContainerRegistry
}
