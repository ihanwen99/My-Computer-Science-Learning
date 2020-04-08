# Chapter1 Questions

### Section 1.1

> R1. What is the difference between a host and an end system? List several different types of end systems. Is a Web server an end system?

- 主机和端系统概念上是一样的。
- 端系统：生活中与因特网相连的计算机，智能手机，游戏机等。
- Web 服务器也属于端系统。

> R2. The word protocol is often used to describe diplomatic relations. How does Wikipedia describe diplomatic protocol?

`Protocol` 协议、`diplomatic realtions` 外交关系

> https://en.wikipedia.org/wiki/Protocol_(diplomacy)
>
> In international politics, **protocol** is the etiquette of diplomacy and affairs of state. 

在国际政治中，协议是外交和国家事务的礼节（？？？）

> R3. Why are standards important for protocols?

有了标准，协议才能生效，端系统才能基于协议制定的标准进行通信。

### Section 1.2

> R4. List six access technologies. Classify each one as home access, enterprise access, or wide-area wireless access.

1. 住宅接入
   - DSL - 数字用户线 (Digital Subscriber Line)：住户通常从提供本地电话接入的本地电话公司处获得 DSL 因特网接入。使用电话线（双绞铜线），通过频分复用的方式。
   - 电缆：利用的是`有线电视公司`现有的有线电视基础设施。使用传统的同轴电缆传输到家庭中。
   - 光纤入户(FTTH: Fiber To The Home)
   - 卫星链路 和 传统的电话线拨号接入。
2. 企业接入
   - 局域网 (LAN) 将端系统连接到边缘路由器，再与更大的因特网相连。
   - 以太网：使用双绞铜线与一台以太网交换机相连。
   - WiFi (基于802.11技术的无线LAN接入)
3. 广域无线接入
   - 通过蜂窝网提供商的基站来发送和接收分组。
   - 3G、4G、5G & LTE

> R5. Is HFC transmission rate dedicated or shared among users? Are collisions possible in a downstream HFC channel? Why or why not?

HFC（Hybrid Fiber Coax混合光纤同轴电缆网）是用户共享的。它的一个重要的特征就是共享广播媒体，同时下行通道和上行通道不是对称的。

下行过程中可能会出现碰撞，因为用户共享信道。

> R6. List the available residential access technologies in your city. For each type of access, provide the advertised downstream rate, upstream rate, and monthly price.

开放题目

> R7. What is the transmission rate of Ethernet LANs?

 Transmission rate（传输速率）

以太网的传输速率可以从以太网标准的名字获得：如 10BASE-T, 100BASE-T, 1000BASE-LX 等。名字的第一部分就是这个标准的速率，对应 10Mbps, 100Mbps, 1000Mbps。**各种标准的速率取决于物理层的结构。**

> R8. What are some of the physical media that Ethernet can run over?

**以太网的物理媒介**：在以太网中传输的一个比特从 “发射器” 到 “接收器” 直接经过的路段。

包括：双绞铜线、同轴电缆、多模光纤缆等。

> R9. Dial-up modems, HFC, DSL and FTTH are all used for residential access. For each of these access technologies, provide a range of transmission rates and comment on whether the transmission rate is shared or dedicated.

**来源网络**

| 种类           | 速率                        | 方式 |
| -------------- | --------------------------- | ---- |
| 拨号调制解调器 | 56Kbps                      | 专用 |
| HFC            | 下行42.8Mbps，上行30.7Mbps  | 专用 |
| DSL            | 下行24Mbps，上行2.5Mbps     | 共享 |
| FTTH           | 下行10-20Mbps，上行2-10Mbps | 专用 |

> R10. Describe the most popular wireless Internet access technologies today. Compare and contrast them.

【开放题目】主要就是蜂窝的 4G 和 WiFi

无线设备连接到更大的网络需要通过基站，基站在这两种技术中有不同的实现方式。

- 蜂窝网络：基站是蜂窝塔，可以较远距离传输信息。
- WiFi（IEEE802.11）：基站是无线局域网的接入点（例如家里面的无线路由器），传输距离较近。

### Section 1.3

> R11. Suppose there is exactly one packet switch between a sending host and a receiving host. The **transmission rates** between the sending host and the switch and between the switch and the receiving host are R1 and R2, respectively. Assuming that the switch uses **store-and-forward packet switching**, what is the total end-to-end delay to send a packet of length L? **(Ignore queuing, propagation delay, and processing delay.)**

Transmission rates（传输速率） + store-and-forward packet switching（存储转发分组方式）

**存储转发分组**：交换机必须接受到整个分组，才能开始向输出链路传输该分组的第一个比特。

考察的就是传输速率延时的计算方式：**使用总的长度 除以 传输速率**：
$$
\frac{L}{R1}+\frac{L}{R2}
$$


> R12. What advantage does a **circuit-switched** network have over a **packet-switched** network? What advantages does **TDM have over FDM** in a circuit-switched network?

Circuit-switched（电路交换网络）的优势：

- 预先分配链路的使用，在网络链路上预留了恒定的传输速率。放松放就能够以**确保**的恒定速率向接收方传输数据。

Packet-switched（分组交换）的优势：

- 更好的带宽共享
- 比电路交换更加简单、高效、实现成本更低

**TDM（时分复用）**和 **FDM（频分复用）**：

- FDM：每条电路连续地得到部分带宽
- TDM：每条电路在短时间间隙中周期地得到全部带宽

TDM能更充分地占用带宽，并且在少用户数上具有更加明显的效果。

TDM先把链路在时域上分割为帧，然后在每帧中划分出时隙，每个用户在每帧中享有一个时隙。这样不仅做到了为用户分配链路，而且每个用户在属于他的时隙中能享用整条链路的带宽。

> R13. Suppose users share a 2 Mbps link. Also suppose each user transmits continuously at 1 Mbps when transmitting, but each user transmits only 20 percent of the time. (See the discussion of statistical multiplexing in Section 1.3.)
>
> - a. When circuit switching is used, how many users can be supported?
> - b. For the remainder of this problem, suppose packet switching is used. Why will there be essentially no queuing delay before the link if two or fewer users transmit at the same time? Why will there be a queuing delay if three users transmit at the same time?
> - c. Find the probability that a given user is transmitting.
> - d. Suppose now there are three users. Find the probability that at any given time, all three users are transmitting simultaneously. Find the fraction of time during which the queue grows.

a. 电路交换会预先为用户分配好链路，一旦分配好就会预留着这部分的带宽。一共支持 2Mbps / 1Mbps = 2个用户。

b. **少数量的用户为什么几乎没有时延：**分组的聚合到达速率小于或等于该链路的输出速率，所以通过该链路的分组流基本没有时延。**活跃用户3个：**到达速率超过链路的输出速率，输出队列会边长，排队时延会增加。

c. 20% = 0.2

d. **队列增长的时间比率：**$0.2*0.2*0.2=0.008$

> R14. Why will two ISPs at the same level of the hierarchy often peer with each other? How does an IXP earn money?

- ISP(Internet Service Provider)因特网服务提供商。
- 如果两个级别相同的ISP通过上级ISP进行网络传输，则需要向上一级的ISP支付费用。而通过相互对等， 两个同级别ISP能绕过上级ISP直接进行网络传输，节省费用。两个对等的ISP通常不进行结算。
- IXP(Internet Exchange Point)因特网交换点，是一个提供对等的地方，通常位于一个有自己的交换机的独立建筑物中。对等ISP在IXP中进行网络传输，IXP通过对这部分流量进行结算挣钱。

> R15. Some content providers have created their own networks. Describe Google ’ s network. What motivates content providers to create these networks?

谷歌有跨越全球的大小不一的数据中心， 假设用户要访问的内容存在于某个数据中心中， 如果通过各层ISP到达谷歌的服务器， 会产生一笔不小的流量费。 谷歌的数据中心通过一个遍布全球的网络互联， 这一专用网络独立于公共因特网， 并绕过高层的ISP直接与较低层的ISP对等或在IXP与它们连接， 因而减少了向顶层ISP支付的费用， 同时对其服务最终如何交付给客户有了更多的控制。 （注: 由于部分用户仅能通过顶层ISP访问到谷歌， 因此谷歌也与顶层ISP相连）

### Section 1.4

> R16. Consider sending a packet from a source host to a destination host over a fixed route. List the delay components in the end-to-end delay. Which of these delays are constant and which are variable?

- 处理时延：**检查分组首部**和**决定分组到向何处**所需要的时间。处理时延也包括：**检查比特级别的差错所需要的时间**。通常是**微秒或者更低的数量级**。处理完成之后，路由器会将该分组引向通往路由器B链路之前的**队列**。——Constant Delay.
- 排队时延：在队列中，**分组在链路上等待运输**的时间。一个特定分组的排队时延长度**取决于先期到达的正在排队等待向链路传输的分组数量**。通常是**毫秒到微秒级别**。——Variable Delay.
- 传输时延：将**所有分组的比特推向链路（发射）所需要的时间**。计算公式$\frac{L}{R}$。通常是**毫秒到微秒级别**。——Constant Delay.
- 传播时延：从链路的起点传播到另一台路由器所用的时间。计算公式是传播距离除以传播速度（物理媒介）$\frac{d}{s}$。通常是**毫秒量级**。——Constant Delay.

> R17. Visit the Transmission Versus Propagation Delay applet at the companion Web site. Among the rates, propagation delay, and packet sizes available, find a combination for which the sender finishes transmitting before the first bit of the packet reaches the receiver. Find another combination for which the first bit of the packet reaches the receiver before the sender finishes transmitting.

[DuDuDuu~]

> R18. How long does it take a packet of length 1,000 bytes to **propagate** over a link of distance 2,500 km, propagation speed $2.5* 10^8$ m/s, and transmission rate 2 Mbps? More generally, how long does it take a packet of length L to propagate over a link of distance d, propagation speed s, and transmission rate R bps? Does this delay depend on packet length? Does this delay depend on transmission rate?

注意我们只是要**传播时延**
$$
\frac{2500km}{2.5*10^8 m/s} = 0.01s 
$$


> R19. Suppose Host A wants to send a large file to Host B. The path from Host A to Host B has three links, of rates R1 = 500 kbps, R2 = 2 Mbps, and R3 = 1 Mbps.
> 
> - a. Assuming no other traffic in the network, what is the throughput for the file transfer?
> - b. Suppose the file is 4 million bytes. Dividing the file size by the throughput, roughly how long will it take to transfer the file to Host B?
> - c. Repeat (a) and (b), but now with R2 reduced to 100 kbps.

a. 文件传送的吞吐量取决于**端到端路径上瓶颈链路**的传输速率—— `500kbps`

b. 需要注意 `bytes`
$$
\frac{8*4Mb }{500kbps} = 64s
$$
c. 
$$
\frac{8*4Mb }{100kbps} = 320s
$$

> R20. Suppose end system A wants to send a large file to end system B. At a very high level, describe how end system A creates packets from the file. When one of these packets arrives to a packet switch, what information in the packet does the switch use to determine the link onto which the packet is forwarded? Why is packet switching in the Internet analogous to driving from one city to another and asking directions along the way?

- 端系统A会以固定的大小把大文件拆分为多个小的数据块，然后通过协议栈， 自顶向下地把数据封装为分组并发送到接收端。
- 分组交换机接收到分组后， 会获取**分组首部的一个或多个字段的值**， 然后到自己的转发表中查询该值该对应转发到哪一条链路上。
- 当我们驾车从一个城市到另一个城市时候， 我们只知道目的地， 而不知道具体要走的路径， 但我们可以通过询问路途中的油站或行人得知下一步的具体路径。 分组交换中同样也是**只知道分组源地址和目的地址， 途中要经过数个路由器， 而路由器会根据目的地告诉分组下一条要走的具体路径。**

> R21. Visit the Queuing and Loss applet at the companion Web site. What is the maximum emission rate and the minimum transmission rate? With those rates, what is the traffic intensity? Run the applet with these rates and determine how long it takes for packet loss to occur. Then repeat the experiment a second time and determine again how long it takes for packet loss to occur. Are the values different? Why or why not?

[DuDuDuu~]


### Section 1.5

> R22. List five tasks that a layer can perform. Is it possible that one (or more) of these tasks could be performed by two (or more) layers?

- 一个层可以执行的任务【需要之后来看】：封装本层的报文段，设置各种参数，对接受到的报文段进行差错检查，还可能进行流量设置、分组重组等。
- 多层完成的任务：差错检验

> R23. What are the five layers in the Internet protocol stack? What are the principal responsibilities of each of these layers?

1. **应用层：网络应用程序及他们的应用层协议存留的地方。**应用层协议分布在多个端系统中，一个端系统中的应用程序使用协议与另一个端系统中的交换信息分组，这个分组被称为报文(message)。
2. **运输层：运输层在应用程序端点之间传送应用层报文。**TCP / UDP 协议在这一层。运输层的分组称为报文段(segment)。
3. **网络层：网络层负责将数据报(datagram)的网络层分组从一台主机移动到另一台主机。** IP协议。
4. **链路层：将网络层的数据报封装成链路层的帧(frame)，并且传输到下一个节点。**【物理空间上的切分吗？】一个数据报的传输过程中可能会被沿途不同链路上的不同链路层处理。
5. **物理层：将链路层帧中的一个个比特移动到下一个节点。**这层的协议是链路相关的，同时也和实际传输媒体相关。

> R24. What is an application-layer message? A transport-layer segment? A network layer datagram? A link-layer frame?

- **应用层报文**指的是在**端系统的应用程序之间按照某种协议进行信息交换**的分组。
- **运输层报文段**指的是通过TCP/UDP等运输层协议对应用层报文进行封装后所形成的分组。**运输层首部信息和应用层报文构成了运输层报文段。**添加的信息有可能是：允许接收端运输层向上向适当的应用程序交付报文的信息；差错检测为信息（用于让接收方判断在传输过程中报文中的比特是否改变）。
- **网络层数据报**是对运输层报文段**增加了如源和目的端系统地址等网络层首部信息**进行封装后产生的分组。
- **链路层帧**是对网络层数据报增加了**链路层首部信息（如下一个节点的具体地址）**的封装。

整体来看：**首部字段 + 有效载荷字段** 构成了每一层中分组的元素。

> R25. Which layers in the Internet protocol stack does a router process? Which layers does a link-layer switch process? Which layers does a host process?

路由器处理：物理层、链路层、网络层

链路交换机处理：物理层、链路层

主机处理：物理层、链路层、网络层、传输层、应用层

### Section 1.6

> R26. What is the difference between a virus and a worm?

- **病毒**：一种**需要某种形式的用户交互**来感染用户设备的恶意软件。
- **蠕虫**：一种**无需任何明显用户交互**就能进入设备的恶意软件。

> R27. Describe how a botnet can be created, and how it can be used for a DDoS attack.

- DDoS(Distributed Denial-of-Service) 分布式拒绝服务攻击
- **僵尸网络的产生**：攻击者入侵设备，并进一步感染其他设备。当感染的设备达到一定数量的时候，就变成可以供攻击者操控的僵尸网络。
- **攻击者利用（受害主机形成的）僵尸网络**，让每台主机向目标猛烈发送流量，造成目标服务陷入瘫痪。

> R28. Suppose Alice and Bob are sending packets to each other over a computer network. Suppose Trudy positions herself in the network so that she can capture all the packets sent by Alice and send whatever she wants to Bob; she can also capture all the packets sent by Bob and send whatever she wants to Alice. List some of the malicious things Trudy can do from this position. 

- 窃听 Alice 和 Bob 的对话内容
- 模拟 Alice 或 Bob 发送分组给对方 


