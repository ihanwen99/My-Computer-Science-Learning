## Git 入门

[Git 官方网站](https://git-scm.com/)

### 创建版本库

```bash
$ git init
```

把当前目录转化为 `Git` 可以管理的仓库。

##### 文本文件

`Git` 只能跟踪文本的改动，不能追踪二进制文件的改动（Word / 图片 / 视频）

使用 `Notepad++` 来代替记事本，默认编码设置 `UTF-8 without BOM`

##### 放入Git仓库

第一步，用命令 `git add` 告诉Git，把文件添加到仓库：

```bash
$ git add README.md
```

第二步，用命令 `git commit` 告诉Git，把文件提交到仓库：

```bash
$ git commit -m "Initialize README"
[master (root-commit) b9e7c5a] Initialize README
 1 file changed, 13 insertions(+)
 create mode 100644 README.md
```

## 时光机穿梭

### 版本回退

##### 获取 `Git` 提交的状态

```bash
$ git status
$ git diff

$ git log
$ git log --pretty=oneline
```

##### `Git` 进行版本回退及复原

**当前状态**

```bash
$ git log --pretty=oneline
077d096576e0d2e1357252e0821091fb97ebfe24 (HEAD -> master) b
8bdacb94cd0dc432639a30f61c6a87f70452f717 a
dcee5cab3f8919abdebe86eaf882295fbba3a6ce Update README
b9e7c5aff4e41c753afb1ecf1a890fade93c4ba3 Initialize README
```

**版本回退**

```bash
$ git reset --hard HEAD
HEAD is now at 077d096 b

$ git reset --hard HEAD^
HEAD is now at 8bdacb9 a

$ git reset --hard HEAD^
HEAD is now at dcee5ca Update README
```

**版本复原**

```bash
$ git reflog
dcee5ca (HEAD -> master) HEAD@{0}: reset: moving to HEAD^
8bdacb9 HEAD@{1}: reset: moving to HEAD^
077d096 HEAD@{2}: reset: moving to HEAD
077d096 HEAD@{3}: reset: moving to HEAD
077d096 HEAD@{4}: reset: moving to HEAD
077d096 HEAD@{5}: reset: moving to HEAD
077d096 HEAD@{6}: commit: b
8bdacb9 HEAD@{7}: reset: moving to HEAD
8bdacb9 HEAD@{8}: commit: a
dcee5ca (HEAD -> master) HEAD@{9}: commit: Update README
b9e7c5a HEAD@{10}: commit (initial): Initialize README

$ git reset --hard 077d
HEAD is now at 077d096 b
```

**复原的同时，中间的版本也恢复了**

```bash
$ git log
commit 077d096576e0d2e1357252e0821091fb97ebfe24 (HEAD -> master)
Author: Starky <david990917@qq.com>
Date:   Wed Apr 8 10:57:49 2020 +0800

    b

commit 8bdacb94cd0dc432639a30f61c6a87f70452f717
Author: Starky <david990917@qq.com>
Date:   Wed Apr 8 10:55:26 2020 +0800

    a

commit dcee5cab3f8919abdebe86eaf882295fbba3a6ce
Author: Starky <david990917@qq.com>
Date:   Wed Apr 8 10:52:22 2020 +0800

    Update README

commit b9e7c5aff4e41c753afb1ecf1a890fade93c4ba3
Author: Starky <david990917@qq.com>
Date:   Wed Apr 8 10:49:13 2020 +0800

    Initialize README
```

### 工作区和暂存区

- 工作区：文件夹中看见的目录

- 版本库：隐藏目录 `.git`

  - 版本库里面 `stage` 暂存区

  ![git-repo](README/0.jfif)

第一步： `git add` 把文件添加进去，实际上就是把文件修改添加到暂存区；

第二步： `git commit` 提交更改，实际上就是把暂存区的所有内容提交到当前分支。

当我们创建Git版本库时，Git自动为我们创建了唯一一个 `master` 分支。

### 管理修改

`Git` 跟踪并且管理的是修改，而不是文件。

每次修改，如果不用 `git add` 到暂存区，那就不会加入到 `commit` 中。

### 撤销修改

##### 撤销工作区的修改

`git checkout -- file` 可以丢弃工作区的修改。

```bash
$ git checkout -- readme.txt
```

把 `readme.txt` 文件在工作区的修改全部撤销，这里有两种情况：

- `readme.txt` 修改后还没有被放到暂存区。撤销修改就回到和版本库一模一样的状态；

-  `readme.txt` 已经添加到暂存区后，又进行了修改。撤销修改就回到添加到暂存区后的状态。

总之，是让这个文件回到最近一次 `git commit` 或 `git add` 时的状态。

##### 撤销暂存区的修改

`git reset HEAD ` 把暂存区的修改撤销掉（unstage），重新放回工作区。

```bash
$ git reset HEAD readme.txt
```

### 删除文件

```bash
$ git rm <file>
```

##### 恢复删除的文件

`git checkout` 是用版本库里的版本替换工作区的版本，无论工作区是修改还是删除，都可以“一键还原”。

```bash
$ git checkout -- test.txt
```

**但是！**没有被添加到版本库就被删除的文件，是无法恢复的！

## 远程仓库

使用 `Github` 作为我们的远程仓库。

## 分支管理

### 创建与合并分支

`master `分支是一条线，Git用 `master` 指向最新的提交，再用 `HEAD` 指向 `master`，就能确定当前分支，以及当前分支的提交点：

![1](README/1.png)

每次提交，`master `分支都会向前移动一步。随着不断地提交，`master` 分支的线也越来越长。

当我们创建新的分支，例如 `dev `时，Git新建了一个指针叫 `dev`，指向 `master` 相同的提交，再把 `HEAD` 指向 `dev`，就表示当前分支在 `dev` 上：

![2](README/2.png)

Git创建一个分支很快，因为除了增加一个 `dev` 指针，改变 `HEAD` 的指向，工作区的文件都没有任何变化！

从现在开始，对工作区的修改和提交就是针对 `dev` 分支了，比如新提交一次后，`dev `指针往前移动一步，而 `master `指针不变：

![3](README/3.png)

假如我们在 `dev` 上的工作完成了，就可以把 `dev` 合并到 `master` 上。

Git合并最简单的方法，就是直接把 `master` 指向 `dev` 的当前提交，就完成了合并：

![4](README/4.png)

所以 `Git` 合并分支也很快！就只是改变指针，工作区内容不用改变。

合并完分支之后，甚至可以删除`dev`分支。删除 `dev` 分支就是把 `dev` 指针给删掉，删掉后，我们就剩下了一条 `master` 分支：

![5](README/5.png)

##### 实战

我们创建 `dev` 分支，然后切换到 `dev` 分支：

```bash
$ git checkout -b dev
Switched to a new branch 'dev'
```

`git checkout` 命令加上 `-b` 参数表示创建并切换，相当于以下两条命令：

```bash
$ git branch dev
$ git checkout dev
Switched to branch 'dev'
```

用  `git branch` 命令查看当前分支：

```bash
$ git branch
* dev
  master
```

当 `dev` 分支的工作完成，我们就可以切换回`master`分支：

```bash
$ git checkout master
Switched to branch 'master'
```
![6](README/6.png)

我们把 `dev` 分支的工作成果合并到 `master` 分支上：

```bash
$ git merge dev
```

`git merge` 命令用于合并指定分支到当前分支。

删除 `dev` 分支：

```bash
$ git branch -d dev
```

删除后，查看 `branch`，就只剩下 `master` 分支了：

```bash
$ git branch
* master
```

##### switch

使用 `switch` 来切换分支

```bash
$ git switch -c dev

$ git switch master
```

### 解决冲突

需要手动修复 `冲突的branch`

![7](README/7.png)

使用 `git log --graph` 命令可以看到分支合并图。

### 分支管理策略

对于 `Fast forward` ，删除分支时候，原来的操作就看不到了。所以可以禁用 `Fast forward`。

```bash
$ git merge --no-ff -m "merge with no-ff" dev
```

```bash
$ git log --graph --pretty=oneline --abbrev-commit
```

`master` 应该是非常稳定，在 `dev` 上面进行开发。

![8](README/8.png)



### Bug-分支

##### 处理BUG，然后回到原来的任务

把当前工作现场“储藏”起来，等以后恢复现场后继续工作：

```bash
$ git stash
```

回到 `master` 分支来修改 `bug`：

```bash
$ git checkout master

$ git checkout -b issue-101
```

修改 `bug`：

```bash
$ git add fixr_bug.py

$ git commit -m "fix bug 101"
```

切换回 `master` 分支，完成合并，删除新分支：

```bash
$ git switch master
$ git merge --no-ff -m "merged bug fix 101" issue-101
```

回到 `dev` 继续进行开发：

```bash
$ git switch dev
Switched to branch 'dev'

$ git status
On branch dev
nothing to commit, working tree clean
```

`git stash list` 查看刚才保存的工作现场：

```bash
$ git stash list
stash@{0}: WIP on dev: f52c633 add merge
```

恢复刚才保存的：

- `git stash apply` 恢复，然后使用 `git stash drop` 删除。
- `git stash pop` 恢复的同时，删除 `stash` 的内容。

```bash
$ git stash pop
```

恢复指定的 `stash`：

```bash
$ git stash apply stash@{0}
```

##### 其他分支上同步修复BUG

Git提供了一个`cherry-pick`命令，让我们能复制一个特定的提交到当前分支：

```bash
$ git cherry-pick 4c805e2
```

### 强行删除

```bash
$ git branch -D feature-vulcan
```

### 多人协作

设置连接

```bash
$ git branch --set-upstream-to=origin/dev dev
```

多人协作的工作模式通常是这样：

1. 首先，可以试图用 `git push origin ` 推送自己的修改；
2. 如果推送失败，则因为远程分支比你的本地更新，需要先用 `git pull` 试图合并；
3. 如果合并有冲突，则解决冲突，并在本地提交；
4. 没有冲突或者解决掉冲突后，再用 `git push origin ` 推送就能成功！

如果 `git pull` 提示 `no tracking information` ，则说明本地分支和远程分支的链接关系没有创建，用命令`git branch --set-upstream-to  origin/`。

## 标签管理

### 创建标签

`tag` 是一个让人容易记住的有意义的名字，和跟某个 `commit` 绑在一起。

使用命令 `git tag  ` 就可以打一个新标签：

```bash
$ git tag v1.0
```

使用命令`git tag`查看所有标签：

```bash
$ git tag
v1.0
```

对 **特定的某次提交** 打标签，提交对应的 `commit id` 是`f52c633`，敲入命令：

```bash
$ git tag v1.9 f52c633
```

### 删除标签

```bash
$ git tag -d v0.1
```

推送标签到远程：

```bash
$ git push origin v1.0

$ git push origin --tags
```

删除远程标签：

```bash
$ git tag -d v0.9

$ git push origin :refs/tags/v0.9
```

