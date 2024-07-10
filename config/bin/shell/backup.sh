#!/bin/bash

set -e

# Define the range of years
start_year=2019
end_year=2020
commits_per_year=50

# Set your GitHub username, email, and repository name
github_username="pxcs"
github_email="sulabaziz09@gmail.com"
repository_name="DiscordRat-CMD"

# Set Git config
git config user.name "pxcs"
git config user.email "sulabaziz09@gmail.com"

for year in $(seq $start_year $end_year); do
    for i in $(seq 1 $commits_per_year); do
        # Generate a random date within the year
        month=$(printf "%02d" $((RANDOM % 12 + 1)))
        day=$(printf "%02d" $((RANDOM % 28 + 1)))
        hour=$(printf "%02d" $((RANDOM % 24)))
        minute=$(printf "%02d" $((RANDOM % 60)))
        second=$(printf "%02d" $((RANDOM % 60)))
        date="$year-$month-$day $hour:$minute:$second"

        # Create a commit with the generated date
        echo "Commit for $date" > file-$year-$i.cs
        git add file-$year-$i.cs
        GIT_AUTHOR_DATE="$date" GIT_COMMITTER_DATE="$date" git commit -m "Backdated commit for $date"
    done
done

# Push the changes to the repository
git push origin main
