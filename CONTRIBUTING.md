# Contributing

When contributing to this repository, please first check if the Solution already exist or not. If you wish to provide a different 
approach to same problem make the file as `q{question_number}_v{version_number}.cpp`

Every file should include these Section:

### 1. Details
Author name and their details.
> Note Created and Modified time are not mandatory
```c
/*
EXAMPLE
Author: Sudip Ghosh (sudipghosh9333@gmail.com)
q42.cpp (c) 2022
Desc: Trapping Rain water
Created:  Sun Sep 18 2022 09:04:48 GMT+0530 (India Standard Time)
Modified: 2022-09-18T03:36:21.124Z
*/
```
### 2. Code

### 3. Approach
Write your approach to the problem with proper explanation
```c
// Approach:
// After looking at the question, I thought of using a 2D array to store the characters in the zigzag pattern. But, I realized that it would be a waste of space. So, I thought of using a vector of strings to store the characters in the zigzag pattern. I used a boolean variable goingDown to keep track of the direction of the zigzag pattern. If goingDown is true, then I increment the row number. If goingDown is false, then I decrement the row number. I used a for loop to iterate through the string s. I used a if-else statement to check if the row number is 0 or numRows - 1. If it is, then I change the value of goingDown. I used a for loop to iterate through the vector of strings and append the characters to the string ans. I returned the string ans.
```

### 4. Complexity Analysis
Write your time and space complexity
```c
// Time complexity: O(n^2)
// Space complexity: O(1)
```


## ✅Pull Request Process

1. Fork the repo
2. Add new file or update the existing one.
3. Create a pull request.
4. And you are done🔥

## Code of Conduct

### Our Pledge

In the interest of fostering an open and welcoming environment, we as
contributors and maintainers pledge to making participation in our project and
our community a harassment-free experience for everyone, regardless of age, body
size, disability, ethnicity, gender identity and expression, level of experience,
nationality, personal appearance, race, religion, or sexual identity and
orientation.

### Our Standards

Examples of behavior that contributes to creating a positive environment
include:

* Using welcoming and inclusive language
* Being respectful of differing viewpoints and experiences
* Gracefully accepting constructive criticism
* Focusing on what is best for the community
* Showing empathy towards other community members

Examples of unacceptable behavior by participants include:

* The use of sexualized language or imagery and unwelcome sexual attention or
advances
* Trolling, insulting/derogatory comments, and personal or political attacks
* Public or private harassment
* Publishing others' private information, such as a physical or electronic
  address, without explicit permission
* Other conduct which could reasonably be considered inappropriate in a
  professional setting

### Our Responsibilities

Project maintainers are responsible for clarifying the standards of acceptable
behavior and are expected to take appropriate and fair corrective action in
response to any instances of unacceptable behavior.

Project maintainers have the right and responsibility to remove, edit, or
reject comments, commits, code, wiki edits, issues, and other contributions
that are not aligned to this Code of Conduct, or to ban temporarily or
permanently any contributor for other behaviors that they deem inappropriate,
threatening, offensive, or harmful.

### Scope

This Code of Conduct applies both within project spaces and in public spaces
when an individual is representing the project or its community. Examples of
representing a project or community include using an official project e-mail
address, posting via an official social media account, or acting as an appointed
representative at an online or offline event. Representation of a project may be
further defined and clarified by project maintainers.

### Enforcement

Instances of abusive, harassing, or otherwise unacceptable behavior may be
reported by contacting the project team at [INSERT EMAIL ADDRESS]. All
complaints will be reviewed and investigated and will result in a response that
is deemed necessary and appropriate to the circumstances. The project team is
obligated to maintain confidentiality with regard to the reporter of an incident.
Further details of specific enforcement policies may be posted separately.

Project maintainers who do not follow or enforce the Code of Conduct in good
faith may face temporary or permanent repercussions as determined by other
members of the project's leadership.

### Attribution

This Code of Conduct is adapted from the [Contributor Covenant][homepage], version 1.4,
available at [http://contributor-covenant.org/version/1/4][version]

[homepage]: http://contributor-covenant.org
[version]: http://contributor-covenant.org/version/1/4/
