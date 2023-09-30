# CSCI 340 Assignment 1

## Introduction to Git and GitHub (x pts)

### Summary

The purpose of this assignment is for students to get set up on GitHub, learning
the basic workflow that will be used for assignment submissions for the course.

Note: If you are already reading this in your own GitHub repo, you can skip to the relevant portion.

### Step 1: Get a GitHub Account

In order to complete this assignment, you will need to have an account at 
[GitHub (`https://github.com`)](https://github.com). If you do not have one yet,
it will be necessary to create one.

### Step 2: Accept the Assignment Invitation

Your professor will provide you with a link to the GitHub Classroom Assignment. You will need
to click that invitation link and accept it. This will create a personalized `git` repo for you on GitHub that you 
will use to complete the rest of the assignment. GitHub will provide you with a link to that repo that you should keep,
as it will be used in the steps below.

### Step 3: Clone your Repo to Turing/Hopper

You will need to clone the repo from the link that GitHub generates for you after acceptance of
the invitation. This creates a local (to the NIU server) copy that can be edited as needed, and you can compile and
test your code on this copy.

`git clone YOUR_REPO_URL_GOES_HERE`

When interacting with the remote (GitHub version) repo, you will be required to log in. GitHub used to accept text username/password authentication, but they made a decision to disable that authentication method, so you will need to choose one of the methods that still works and configure your Turing/Hopper session to use that when talking to GitHub.

#### SSH Public Key Authentication (Recommended)

One common method of authentication is to use asymmetric encryption. You generate a pair of cryptographic keys; one private (don't ever share it), and the other public (this is the one you can share). You can use the `ssh-keygen` program on Turing or Hopper to generate your keys, and put the public key information in your GitHub account settings. This is more secure than the other option, and I recommend that you choose this.

GitHub has documentation on how to do this:  
[https://docs.github.com/en/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent)

John Winans recorded a video for a previous section of CSCI 340 where he went through these steps, which can be viewed at 
[https://www.youtube.com/watch?v=CdZa8MzLtjQ](https://www.youtube.com/watch?v=CdZa8MzLtjQ)

#### GitHub Token Authentication

You can generate a token (a unique alphanumeric string used for authentication purposes) in the GitHub website's
settings, and make sure that the correct environment variable contains that token when the `git` command looks
for it. This involves having your token in an environment variable that could potentially be read by other 
programs, so it's not as secure as the SSH method above. There are instructions on the GitHub site if you want to go this route.


### Step 4: Create a `development` branch

A `git` repo can contain several simultaneous versions of your source code. The default branch is called `master` or `main`. 

You need to create a new branch, called `development`, and all of your work will be done on that branch.

Creating the branch is as simple as typing `git branch development` in the directory you cloned the repo to.

Once the branch is created, you can change to the new branch with `git checkout development`. Make sure you are in this branch when adding files and committing changes.

**WARNING: YOU WILL LOSE POINTS IF YOU COMMIT ANY CHANGES IN THE `main`/`master` BRANCH.**

### Step 5: Add Necessary Comments to the File and Commit

When you clone the repo from GitHub, there will already be several files present. They implement a simple program that has been
intentionally broken. **Before** we worry about fixing the program, we're going to add some documentation, and commit that documentation to the repo.

You must add a documentation box at the top of the `assign1.cc` file, in the following format:

~~~~~ {.text}
/**********************************************************************************************
 * NIU CSCI 340 Section YOUR_SECTION                                                          *
 * Assignment 1                                                                               *
 * YOUR FULL NAME - YOUR Z-ID - YOUR GITHUB USERNAME                                          *
 *                                                                                            *
 *   I certify that everything I am submitting is either provided by the professor for use in *
 * the assignment, or work done by me personally. I understand that if I am caught submitting *
 * the work of others (including StackOverflow or ChatGPT) as my own is an act of Academic    *
 * Misconduct and will be punished as such.                                                   *
 *                                                                                            *
 **********************************************************************************************/
~~~~~
**Make sure you provide your own name, section number, ZID, and GitHub username in this comment. If the grader cannot find this information, they will not be able to assign you a grade for your work.**

**DO NOT MAKE ANY OTHER CHANGES TO THE FILE AT THIS STAGE. THERE IS AN INTENTIONAL BUG THAT YOU SHOULD LEAVE UNFIXED FOR NOW**

Once you've added the comment to your file, save the changes, and use `git` to add the changes
to the `development` branch. This can be achieved with `git add assign1.cc`.

Having added the file to the list of files whose changes will be committed, you will now be ready 
to do your first commit. This is as simple as typing `git commit` and typing an appropriate 
description of the changes you made to the code at the prompt provided.

Note that commits are done to the local copy of the repo (on turing or hopper). When you're ready for those changes to appear on the remote, GitHub repo, you will need to push those changes over.

### Step 6: Fix What is Broken

If you run `make`, you will notice that the current code does not compile. There was an error intentionally 
left in the C++ file. It is not hard to find, so go ahead and fix it, then repeat the process of adding the 
file, committing the new change separately from the commit where the comment was added.

### Step 7: Push your local commits to the remote server

Graders won't have access to your local copy of the repo, so you'll need to make sure that the commits that you 
have done are present on the remote server. This is done with the command `git push`. When you run this, `git`
connects to the remote server (GitHub) in this case, and all of the changes you've commmitted are sent to the server, 
where they will be visible to anyone with access to the remote repo.

### Step 8: Signal your completion of the assignment by adding a pull request

When you have completed the earlier steps, go to your repo link in your web browser and add a pull request. 
A pull request is a request to have changes present in a branch merged into the `main`/`master` branch. It allows
teams to work separately and have their work safely added in when done.

**We** are using pull requests because they're a good way of signaling that you have completed your assignment. You will not be able to add a pull request if you did all of your changes in the `main` or `master` branch, so it is very important to have followed the instructions to do your work in the `development` branch only.

**DO NOT ACCEPT THE PULL REQUEST. JUST CREATE IT AND LEAVE IT THERE FOR THE GRADER TO SEE**

### Grading Considerations

 - The comment inserted in the first commit should match the one provided, with your information inserted in the appropriate locations.
 - Did you put your name/section/zid in the comments? If we can't link the repo to your real identity, we can't give you any points.
 - You must have created and used the `development` branch. No changes should be committed in the `main` or `master` branch.
 - The second commit must fix the error in the file, and it must compile. Do not commit before this is the case.
 - The TA will be checking your repo for the pull request before considering your work to have been submitted. Make sure you make the pull request before the assignment deadline.
 - Although you can make whatever changes you want to your local repo, no changes other than the ones required should be committed to the repo.
