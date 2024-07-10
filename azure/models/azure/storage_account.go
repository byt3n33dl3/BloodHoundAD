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

type StorageAccount struct {
	Entity

	ExtendedLocation ExtendedLocation         `json:"extendedLocation,omitempty"`
	Identity         ManagedIdentity          `json:"identity,omitempty"`
	Kind             string                   `json:"kind,omitempty"`
	Location         string                   `json:"location,omitempty"`
	Name             string                   `json:"name,omitempty"`
	Properties       StorageAccountProperties `json:"properties,omitempty"`
	Sku              Sku                      `json:"sku,omitempty"`
	Tags             map[string]string        `json:"tags,omitempty"`
	Type             string                   `json:"type,omitempty"`
}

func (s StorageAccount) ResourceGroupName() string {
	parts := strings.Split(s.Id, "/")
	if len(parts) > 4 {
		return parts[4]
	} else {
		return ""
	}
}

func (s StorageAccount) ResourceGroupId() string {
	parts := strings.Split(s.Id, "/")
	if len(parts) > 5 {
		return strings.Join(parts[:5], "/")
	} else {
		return ""
	}
}

type StorageAccountList struct {
	NextLink string           `json:"nextLink,omitempty"` // The URL to use for getting the next set of values.
	Value    []StorageAccount `json:"value"`              // A list of storage accounts.
}

type StorageAccountResult struct {
	SubscriptionId string
	Error          error
	Ok             StorageAccount
}
