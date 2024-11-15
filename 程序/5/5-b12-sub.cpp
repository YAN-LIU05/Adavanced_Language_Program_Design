/* 2352018 信06 刘彦 */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return 0只是一个示例，可改变 */

/* 不允许定义任何形式的外部全局、静态全局、宏定义、只读变量 */

/***************************************************************************
  函数名称：
  功    能：求字符串str的长度
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char str[])
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;    //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：将字符串s2追加到s1后面,含\0
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcat(char s1[], const char s2[])
{
    // 找到s1的结束位置
    int i = 0;
    while (s1[i] != '\0') 
    {
        i++;
    }

    // 将s2追加到s1后面
    int j = 0;
    while (s2[j] != '\0') 
    {
        s1[i++] = s2[j++];
    }

    // 在s1的末尾添加空字符
    s1[i] = '\0';

    return 0;   //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：将字符串s2的前1en个字符追加到s1后面,并添加\0，若1en比s2的长度大,则追加整个s2即可(含\0)
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncat(char s1[], const char s2[], const int len)
{
    // 找到s1的结束位置
    int i = 0;
    while (s1[i] != '\0') 
    {
        i++;
    }

    // 将s2的前len个字符追加到s1后面
    int j = 0;
    while (j < len && s2[j] != '\0') 
    {
        s1[i++] = s2[j++];
    }

    // 在s1的末尾添加空字符
    s1[i] = '\0';

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：将字符串s2复制到s1中,覆盖s1中原内容,复制时包含\0
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcpy(char s1[], const char s2[])
{
    int i = 0; // 初始化索引变量i

    // 复制s2到s1，直到遇到空字符
    while (s2[i] != '\0') 
    {
        s1[i] = s2[i];
        i++;
    }

    // 在s1的末尾添加空字符
    s1[i] = '\0';


    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：将字符串s2的前1en个字符复制到s1中,复制时不含\0，若len比s2的长度大,复制s2长度个字符即可(不含\0)
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncpy(char s1[], const char s2[], const int len)
{
    int i;

    // 复制s2到s1，最多复制len个字符
    for (i = 0; i < len && s2[i] != '\0'; i++) 
    {
        s1[i] = s2[i];
    }
    /*如果len小于或等于s2的长度，则复制len个字符
      如果len大于s2的长度，则复制s2的长度个字符
      剩余的s1[i]将不会被赋值，循环会在遇到s2的空字符时停止*/

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：比较字符串s1和s2的大小,英文字母要区分大小写
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char s1[], const char s2[])
{
    int i = 0;

    // 逐个字符比较s1和s2
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) 
    {
        i++;
    }

    // 如果s1中的字符大于s2中的字符，返回第1个不相等字符的ASCII差值
    if (s1[i] != s2[i]) 
    {
        return s1[i] - s2[i];   //return值可根据需要修改
    }
    

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：比较字符串s1和s2的大小,英文字母不分大小写
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char s1[], const char s2[])
{
    int i = 0;
    char ch1, ch2;

    // 逐个字符比较s1和s2，直到遇到字符串结束或找到不同的字符
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        ch1 = s1[i];
        ch2 = s2[i];

        // 如果是大写字母，转换为小写
        if (ch1 >= 'A' && ch1 <= 'Z') 
        {
            ch1 += 'a' - 'A';
        }
        if (ch2 >= 'A' && ch2 <= 'Z') 
        {
            ch2 += 'a' - 'A';
        }

        // 比较转换后的字符
        if (ch1 != ch2) 
        {
            return ch1 - ch2;
        }

        i++;
    }

    // 如果s1或s2结束，比较它们是否完全相同
    if (s1[i] != s2[i]) 
    {
        return s1[i] - s2[i];
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：比较字符串s1和s2的前len个字符的大小,英文字母要区分大小写
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char s1[], const char s2[], const int len)
{
    int i = 0;

    // 逐个字符比较s1和s2的前len个字符
    while (i < len && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
    {
        i++;
    }

    // 如果s1中前len个字符大于s2中前len个字符，返回第1个不相等字符的ASCII差值
    if (i < len && s1[i] != s2[i])
    {
        return s1[i] - s2[i];   //return值可根据需要修改
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：比较字符串s1和s2的前len个字符的大小,英文字母不分大小写
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char s1[], const char s2[], const int len)
{
    int i = 0;
    char ch1, ch2;

    // 逐个字符比较s1和s2的前len个字符
    while (i < len && s1[i] != '\0' && s2[i] != '\0')
    {
        ch1 = s1[i];
        ch2 = s2[i];

        // 如果是大写字母，转换为小写
        if (ch1 >= 'A' && ch1 <= 'Z')
        {
            ch1 += 'a' - 'A';
        }
        if (ch2 >= 'A' && ch2 <= 'Z')
        {
            ch2 += 'a' - 'A';
        }

        // 比较转换后的字符
        if (ch1 != ch2)
        {
            return ch1 - ch2;
        }

        i++;
    }

    // 如果s1或s2结束，比较它们是否完全相同
    if (i < len && s1[i] != s2[i])
    {
        return s1[i] - s2[i];
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：将字符串str中所有小写字母均转为大写,其它字符不变,转换后放在原串中
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strupr(char str[])
{
    int i = 0;

    // 遍历字符串直到遇到空字符'\0'
    while (str[i] != '\0') 
    {
        // 检查字符是否为小写字母
        if (str[i] >= 'a' && str[i] <= 'z') 
        {
            // 将小写字母转换为大写
            str[i] -= 'a' - 'A';
        }
        i++;
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：将字符串str中所有大写字母均转为小写,其它字符不变,转换后放在原串中
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlwr(char str[])
{
    int i = 0;

    // 遍历字符串直到遇到空字符'\0'
    while (str[i] != '\0')
    {
        // 检查字符是否为大写字母
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            // 将大写字母转换为小写
            str[i] += 'a' - 'A';
        }
        i++;
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：在字符串 str中寻找字符ch第1次出现的位置,顺序是从左到右
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char str[], char ch)
{
    int i = 0;

    // 遍历字符串
    while (str[i] != '\0')
    {
        // 如果当前字符是ch
        if (str[i] == ch)
        {
            return 1 + i; // 返回1 - n
        }
        i++; 
    }

    // 如果没有找到ch，返回0
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：在字符串str中寻找字符串substr第1次出现的位置,顺序是从左到右
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char str[], const char substr[])
{
    int i, j;
    int st = tj_strlen(str);
    int su = tj_strlen(substr);

    for (i = 0; i <= st - su; i++)  // 确保str[i + j]在str内
    { 
        for (j = 0; j < su; j++)
        {
            if (str[i + j] != substr[j]) 
            {
                break; // 如果字符不匹配，跳出内层循环
            }
        }
        if (j == su) 
        {
            return i + 1; // 找到匹配的substr，返回1 - n
        }
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：在字符串 str中寻找字符ch第1次出现的位置,顺序是从右到左
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char str[], const char ch)
{
    int len = tj_strlen(str); // 获取字符串str的长度
    int i;

    // 从字符串末尾开始向前遍历
    for (i = len - 1; i >= 0; i--)
    {
        // 如果当前字符是ch
        if (str[i] == ch)
        {
            return i + 1;  // 返回1 - n
        }
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：在字符串str中寻找字符串substr第1次出现的位置,顺序是从右到左
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char str[], const char substr[])
{
    int i, j;
    int st = tj_strlen(str);
    int su = tj_strlen(substr);

    for (i = st - 1; i >= 0; i--)  // 确保str[i + j]在str内
    {
        for (j = 0; j < su; j++)
        {
            if (str[i + j] != substr[j])
            {
                break; // 如果字符不匹配，跳出内层循环
            }
        }
        if (j == su)
        {
            return i + 1; // 找到匹配的substr，返回1 - n
        }
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：字符串反转,放入原串中
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrev(char str[])
{
    int len = tj_strlen(str) - 1; // 获取字符串长度，减1跳过结尾的空字符
    int i = 0;
    int j = len;
    char mid;

    // i从左到右，j从右到左
    while (i <= j)
    {
        // 交换两个字符
        mid = str[i];
        str[i] = str[j];
        str[j] = mid;
        i++;
        j--;
    }

    return 0; //return值可根据需要修改
}
