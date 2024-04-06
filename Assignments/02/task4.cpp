/*
*   Name: Ibrahim Johar Farooqi 
*   ID: 23K-0074
*   Task 4
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int MAXCOMMENTS = 10;
const int MAX_FEED_SIZE = 10;
const int PRIME_CONST = 31;

int hashAlgo(string stringKey)
{
    int intHashCode = 0;
    for (int i = 0; i < stringKey.length(); i++)
    {
        intHashCode += stringKey[i] * pow(PRIME_CONST, i);
    }
    return intHashCode;
}

class Post
{
    private:
        static int id;
        int postID;
        int views;
        int likes;
        string *comments;
        int commentCount;
        string content;

    public:
        Post(string c) : content(c), views(0), likes(0), commentCount(0)
        {
            id++;
            postID = id;
            comments = new string[MAX_FEED_SIZE];
            for (int i = 0; i < MAX_FEED_SIZE; ++i)
            {
                comments[i] = "";
            }
        }

        void addComment(string c)
        {
            if (commentCount < MAX_FEED_SIZE)
            {
                comments[commentCount++] = c;
                views++;
                cout << "Comment added to Post " << postID << "\n";
            }
            else
            {
                cout << "Maximum number of comments added" << "\n";
            }
        }

        void addLike() { likes++; views++; cout << "Post " << postID << " liked" << "\n"; }

        void displayPostDetails()
        {
            cout << "\nPost Details:\n";
            cout << "Post ID: " << postID << "\n";
            cout << "Content: " << content << "\n";
            cout << "Likes: " << likes << "\n";
            cout << "Views: " << views << "\n";
            cout << "Post comments:\n";
            for (int i = 0; i < commentCount; i++)
            {
                cout << comments[i] << "\n";
            }
        }

        //setters
        void setLikes(int l) { likes = l; }
        void setViews(int v) { views = v; }

        //getters
        int getLikes() const { return likes; }
        int getViews() const { return views; }
        int getPostID() const { return postID; }
        int getCommentCount() const { return commentCount; }

        ~Post()
        {
            delete[] comments;
        }
};

int Post::id = 0;

class User
{
    private:
        string username;
        string email;
        string password;
        string nonHashPassword;
        string usertype;
    public:
        User(string u, string e, string p, string type) : 
            username(u), email(e), nonHashPassword(p), usertype(type)
        {
            password = hashAlgo(p);
        }
        
        bool verificationOfUser() //verify user info with taking user input
        {
            string pass;
            string userN;
            string eMail;
            cout << "Enter Your Username: ";
            getline(cin, userN);
            cout << "Enter Your Email: ";
            getline(cin, eMail);
            cout << "Enter Your Password: ";
            getline(cin, pass);

            if (userN == username && eMail == email && pass == nonHashPassword)
            {
                cout << "User has been verified" << "\n";
                return true;
            }
            else
            {
                cout << "Invalid user credentials entered.\n" << endl;
                return false;
            }
        }

        //setters
        void setUsername(string u) { username = u; }
        void setEmail(string e) { email = e; }
        void setPassword(string p) { password = p; }
        void setUsertype(string t) { usertype = t; }

        //getters
        string getUsername() const { return username; }
        string getEmail() const { return email; }
        string getPassword() const { return password; }
        string getUsertype() const { return usertype; }

        void display() const
        {
            cout << "\nUser Details:\n";
            cout << "Username: " << username << "\n";
            cout << "Email: " << email << "\n";
            cout << "Usertype: " << usertype << "\n";
        }
};

class RegularUser : public User 
{
    private:
        static Post *feed[MAX_FEED_SIZE];
        static int postCount;
        Post *posts[5];

    public:
        RegularUser(string u, string e, string p, string t) : User(u, e, p, t)
        {
            for (int i = 0; i < 5; ++i)
            {
                posts[i] = nullptr;
            }
        }

        virtual void addToFeed(Post *post)
        {
            int flag = 1;
            if (postCount < MAX_FEED_SIZE)
            {
                for (int i = 0; i < 5; i++)
                {
                    if (posts[i] == nullptr)
                    {
                        posts[i] = post;
                        feed[postCount] = posts[i];
                        postCount++;
                        flag = 0;
                        break;
                    }
                }
                if (flag == 1) { cout << "Upgrade to Business User Class to add more posts"; }
            }
            else 
            {
                cout << "Maximum number of posts have been added to feed.\n";
            }
        }

        virtual void viewFeed()
        {
            for (int i = 0; i < postCount; i++)
            {
                if (feed[i] != nullptr)
                {
                    feed[i]->displayPostDetails();
                }
            }
        }
};

Post *RegularUser::feed[MAX_FEED_SIZE] = {nullptr};
int RegularUser::postCount = 0;

class BusinessUser : public RegularUser
{
    private:
        static Post *feed[MAX_FEED_SIZE];
        Post *businessPosts[MAX_FEED_SIZE];
        static int postCount;
        int promotedPosts;

    public:
        BusinessUser(string u, string e, string p, string t) : 
            RegularUser(u, e, p, t), promotedPosts(0)
        {
            for (int i = 0; i < MAX_FEED_SIZE; i++)
            {
                businessPosts[i] = nullptr;
            }
        }

        void promotePost(Post *post)
        {
            if (getUsertype() == "Business" || getUsertype() == "business")
            {
                if (promotedPosts < 10)
                {
                    post->setLikes(post->getLikes() * 2);
                    post->setViews(post->getViews() * 3);
                    promotedPosts++;
                    cout << "Post " << post->getPostID() << " promoted\n";
                }
                else 
                {
                    cout << "Maximum number of posts promoted.\n";
                }
            }
            
        }

        void addToFeed(Post *post)
        {
            if (postCount < MAX_FEED_SIZE)
            {
                for (int i = 0; i < MAX_FEED_SIZE; i++)
                {
                    if (businessPosts[i] == nullptr)
                    {
                        businessPosts[i] = post;
                        feed[postCount] = businessPosts[i];
                        postCount++;
                        break;
                    }
                }
            }
            else
            {
                cout << "Maximum number of posts have been added to feed.\n";
            }
        }

        void viewFeed()
        {
            for (int i = 0; i < MAX_FEED_SIZE; i++)
            {
                if (businessPosts[i] != nullptr)
                {
                    businessPosts[i]->displayPostDetails();
                }
            }
        }
};

Post *BusinessUser::feed[MAX_FEED_SIZE] = {nullptr};
int BusinessUser::postCount = 0;

int main()
{
    cout << "Ibrahim Johar Farooqi - 23K-0074 - Task 4\n\n";
    
    //regular user implementation
    RegularUser r_user1("IbrahimJohar", "ibrahimj@gmail.com", "pass123", "regular");

    Post post1("Post One - Regular User.");
    Post post2("Post Two - Regular User.");
    Post post3("Post Three - Regular User.");
    
    cout << "Regular User Verification:\n";
    bool flag = r_user1.verificationOfUser();

    if (flag)
    {
        r_user1.addToFeed(&post1);
        r_user1.addToFeed(&post2);
        r_user1.addToFeed(&post3);

        cout << "\nPosts Liked by Regular User:\n";
        post1.addLike();
        post2.addLike();
        post3.addLike();

        cout << "\nComments Added by User:\n";
        post1.addComment("First comment here.");
        post1.addComment("Second comment on first post?");
        post2.addComment("Comments are good.");
        post3.addComment("Comments section is thriving.");

        cout << "\nRegular User Feed:\n";
        r_user1.viewFeed();

        r_user1.display();
        cout << "\n";
    }

    //business user implementation
    BusinessUser b_user1("JacobMiller", "jacob@gmail.com", "pass234", "business");

    Post post4("Post One - Business User.");
    Post post5("Post Two - Business User.");
    Post post6("Post Three - Business User.");

    cout << "Business User Verification:\n";
    flag = b_user1.verificationOfUser();

    if (flag)
    {
        b_user1.addToFeed(&post4);
        b_user1.addToFeed(&post5);
        b_user1.addToFeed(&post6);

        cout << "\nBusiness User Posts Liked:\n";
        post4.addLike();
        post5.addLike();
        post6.addLike();

        cout << "\nSelect Post Promoted:\n";
        b_user1.promotePost(&post5);

        cout << "\nComments Added by User:\n";
        post4.addComment("Business is booming.");
        post5.addComment("KPIs are up!");
        post6.addComment("economy is thriving right?");

        cout << "\nBusiness User Feed:\n";
        b_user1.viewFeed();

        cout << "\nSelect Post Promoted(Again):\n";
        b_user1.promotePost(&post5);

        cout << "\nBusiness User Feed:\n";
        b_user1.viewFeed();

        b_user1.display();
    }

    return 0;
}
