#ifndef __zxzToast_h__
#define __zxzToast_h__
#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

/**
 * ������Android��toast�ؼ��Ľڵ�, ��һ�����������������ڵ����. �����������ֻ����ʾ����, ���ݽڵ����
 * Ϊ��������. �����ڵ������һ����������Ľڵ�, ����CCNinePatchSprite.
 */
class  zxzToast : public CCNode {
private:
	/// shared queue of all toasts
	//static vector<zxzToast*>* s_toastQueue;
	 //CCArray* s_toastQueue;
	//CCArray* s_toastQueue;

	/// background node
	CCNode* m_bg;

	/// content node
	CCNode* m_content;

	/// margin left
	float m_leftMargin;

	/// margin right
	float m_rightMargin;

	/// margin top
	float m_topMargin;

	/// margin bottom
	float m_bottomMargin;

	/// dirty flag
	bool m_dirty;

	/// width of default background texture
	float m_defaultBgWidth;

	/// height of default background texture
	float m_defaultBgHeight;

	/// true means background is default
	bool m_useDefaultBg;

	/// duration in seconds
	float m_duration;

	/// toast position x
	float m_toastPositionX;

	/// toast position y
	float m_toastPositionY;

	/// true means use default toast position
	bool m_useDefaultPosition;

	/// true means this toast is shown immediately
	//bool m_immediately;

private:
	void onToastFadedOut(CCNode* sender, void* data);

protected:
	/**
	 * Constructor
	 *
	 * @param bg background node
	 * @param content content node
	 * @param duration duration in seconds
	 */
	zxzToast(CCNode* bg, CCNode* content, float duration);

	/// clear all pending toast and release queue
	//static void clear();

	/// perform layout of toast, including set position and size
	void layout();

	/// show a toast
	void putToScene();

	/// remove background node
	void removeBackground();

	/// add background node to running scene
	void addBackground();

	/// remove content node from bg
	void removeContent();

	/// add content node to bg node
	void addContent();

	/// Set background node
	void setBackground(CCNode* bg);

	/// Set content node
	void setContent(CCNode* c);

public:
	virtual ~zxzToast();

	/**
	 * Create a toast with background and content node
	 *
	 * @param bg background node
	 * @param content content node
	 * @param duration duration in seconds
	 */
	static zxzToast* create(CCNode* bg, CCNode* content, float duration);

	/**
	 * Create a toast with content node, it uses default background
	 *
	 * @param content content node
	 * @param duration duration in seconds
	 */
	static zxzToast* create(CCNode* content, float duration);

	/**
	 * \if English
	 * Create a toast with background node, and content text, the text
	 * will be assigned to a \link wyLabel wyLabel\endlink
	 *
	 * @param bg background node
	 * @param text content text string
	 * @param duration duration in seconds
	 * \else
	 * ����һ��toast, ��ָ�������ڵ����������. ���ֻᱻ����һ��\link wyLabel wyLabel\endlink�ڵ�.
	 *
	 * @param bg �����ڵ�
	 * @param text ��������
	 * @param duration ������ʾʱ��, ʱ�䵽��ὥ����ʧ
	 * \endif
	 */
	static zxzToast* create(CCNode* bg, const char* text, float duration);

	/**
	 * \if English
	 * Create a toast with content text. The background will be set to default style
	 *
	 * @param text content text
	 * @param duration duration in seconds
	 * \else
	 * ����һ��Toast�ڵ�, ָֻ����������. ���������ó�ȱʡ��ʽ
	 *
	 * @param text ��������
	 * @param duration ������ʾʱ��, ʱ�䵽��ὥ����ʧ
	 * \endif
	 */
	//static zxzToast* create(const char* text, float duration);
	static zxzToast* create(const char* backImageFile, const char* text, float duration);

	/**
	 * \if English
	 * Show this toast
	 *
	 * @param immediately true means the toast should be visible right now, or false
	 * 		means it will be shown after previous toast is disappeared, default is false
	 * \else
	 * ��ʾ���toast
	 *
	 * @param immediately true��ʾ������ʾ���toast. false��ʾ����֮ǰһ��toast��ʧ֮������ʾ,
	 * 		ȱʡ��false
	 * \endif
	 */
	//void show(bool immediately = false);
	void show();

	/**
	 * \if English
	 * Get background node
	 * \else
	 * �õ������ڵ�
	 * \endif
	 */
	inline CCNode* getBackground() { return m_bg; }

	/**
	 * \if English
	 * Get content node
	 * \else
	 * �õ����ݽڵ�
	 * \endif
	 */
	inline CCNode* getContent() { return m_content; }

	/**
	 * \if English
	 * Set margin between content and background node.
	 * \else
	 * �������ݽڵ�ͱ����ڵ�߽�ľ���
	 * \endif
	 */
	void setMargin(float top, float left, float right, float bottom);

	/**
	 * \if English
	 * Get left margin
	 * \else
	 * �õ���߿�϶
	 * \endif
	 */
	inline float getLeftMargin() { return m_leftMargin; }

	/**
	 * \if English
	 * Get right margin
	 * \else
	 * �õ��ұ߿�϶
	 * \endif
	 */
	inline float getRightMargin() { return m_rightMargin; }

	/**
	 * \if English
	 * Get top margin
	 * \else
	 * �õ��ϱ߿�϶
	 * \endif
	 */
	inline float getTopMargin() { return m_topMargin; }

	/**
	 * \if English
	 * Get bottom margin
	 * \else
	 * �õ��±߿�϶
	 * \endif
	 */
	inline float getBottomMargin() { return m_bottomMargin; }

	/**
	 * \if English
	 * Set desired position where toast will be shown. If not set,
	 * toast will be placed in (wyDevice::winWidth / 2, wyDevice::winHeight * 4 / 5)
	 * \else
	 * ����toast���ֵ�λ��, ���������. ��ȱʡ�������Ļ�м�ƫ�µ�λ��, ����������:
	 * (wyDevice::winWidth / 2, wyDevice::winHeight * 4 / 5)
	 * \endif
	 */
	void setToastPosition(float x, float y);
};

// toast queue
//CCArray* zxzToast::s_toastQueue = NULL;
// toast default background raw png data array
//
static const unsigned int _toast_bg_png[] = {
	0x474e5089,0xa1a0a0d,0xd000000,0x52444849,0x32000000,0x32000000,0x608,0x883f1e00,0xb1,0x59487009,0xb000073,0xb000013,0x9a000113,0x189c,0x43694d0a,0x68505043,0x736f746f,0x20706f68,0x20434349,0x666f7270,0x656c69,0x9dda7800,0x93587753,0xdf3e16f7,0x560f65f7,0xb1f0d842,0x816c97,0x8ac2322,0xa25910c8,0x61009210,0x40121084,0xa8885c5,0x11151456,0xc455489c,0x480ad582,0xa0e2889d,0x4167b828,0x8b5a888a,0xee385c55,0xb5a7dc1f,0xedef7a7d,0xfbd7fbed,0xe79ce7bc,0xcf79cefc,0x1211800f,0xa2e69126,0x5239006a,0xd83a3c85,0x484f8f1f,0x80bdc9c4,0xe0481502,0xe6102004,0x567c2cb,0xf00000c5,0x7e787903,0xfc3fb074,0x6faf01,0xd5700002,0xc712242e,0xba83ffe1,0x572650,0xe0009120,0xbe71222,0x529001,
	0xc8542ec8,0x18c80014,0xb353b000,0x94000a64,0x796c0000,0x22427c,0xec000daa,0x53e49f4,0x93a9d800,0xd80017dc,0x8a91ca2,0x18d00,0x24472899,0xbb4002,0x52815560,0xc2c0022c,0x40aca000,0xc0042e22,0x598001ae,0x24732b6,0x5bd80,0x90588e76,0x60400f,0x2c429980,0x382000cc,0x1e430002,0x2003cd13,0x30a0034c,0xa9e0bfd2,0xb885705f,0xc0000148,0x97cd95cb,0x1433d24b,0x1ad095b8,0xe0f0f277,0xc2e221e2,0x6142b16c,0x66102917,0x9c22e409,0x13239b97,0x4c03e748,0xcce,0xc1d1f91a,0x903f38fe,0xe1e4e6e7,0x6ce766e6,0xa2c5f4ef,0x6ff06bfe,0xf1213e22,0x8cbcfedf,0x10000402,0xdaefcf4e,0xd6e5e55f,0x1c77003,0x6bbf75b0,0xda005ba9,0xdf680056,0xdb335df9,0xa5aa009,0x8bf97ad0,0x40fc3879,0x50a19e1e,0x1c1d3cc8,0xed0b0b0a,
	0xbda16225,0x3e8be330,0x6fe133ff,0xf67e8be0,0xfe1e40fc,0xf07adb,0x99409a71,0x83a3c0ad,0x6e6171fd,0x8e52ae76,0x4204cbe7,0xe7f76e31,0x85c7fe23,0x298efd7f,0xb134e2d1,0x8a152c5c,0xb88958f1,0xc74d2250,0x9152b979,0x95c92144,0x7fe912e2,0x961ff132,0x779309fd,0x86ac000d,0xb64ec04f,0x6ccbb507,0x1ee7ec0,0x580e8b02,0x400076d2,0x8c2df37e,0x910b1a,0x32346710,0xf779,0x8ff9bf93,0x12b40,0xe3a497cd,0xe8bc0000,0x94a85c18,0x8c64c17,0xa0440000,0x41b02a81,0x14c10c07,0x9c0ec0ac,0xc0bc1dc1,0x6610217,0x240c4044,0x42103cc0,0x1c80e406,0x9618a10a,0xc0541941,0xb504d83a,0xa01a03b0,0x10e19a11,0x3831c1b4,0x12e0e70d,0x70eb815c,0x18600617,0xbc18c29e,0x41040986,0x611308c8,0x11883a21,0x22d88e62,0x991708ce,0x6122048e,
	0x80923448,0x88e920a4,0xc5225114,0x2a472c8,0x916a42a9,0xf223485d,0x3914722d,0xfa405c8d,0x20c8db90,0x8afc8a32,0x943147bc,0x351b281,0x407502d4,0x1a1fa8b9,0x73a0c68a,0xf3474d1,0xa296805d,0xb41ad16b,0xb6803d1e,0x4bd1a7a2,0x7475e8,0x638e8a7d,0xe31d180,0x61d98c66,0x45878c5c,0x1a588960,0x6316c726,0x563558e5,0x1d63358f,0x15763758,0x619ec01b,0x22408ef,0xec13808b,0x10845e08,0x90826cc2,0x4c584790,0x25a84358,0x12b423ec,0x95708ba,0xc2318483,0xa8932227,0x7a25b44f,0x78c4f912,0x90b13a62,0x26ac4658,0x211e21ee,0x275e259e,0x935f130e,0xc90e2448,0xa4ee492,0x32902521,0x6b490b49,0x2d48db48,0x3ea453a4,0x9c6910d2,0x90eb264c,0xe4dec96d,0xac80b208,0xb7919720,0x4f900f90,0xc3c9fb92,0x3a14b7e4,0x4ce288c5,0x5224a209,
	0x4a1294a4,0xe53f6535,0x329fa504,0xaaa09942,0x9ea9cd51,0x88aa08d4,0x495a9f3a,0x5076a06d,0xa987532f,0x9a753413,0x169bcd25,0x2da4cb43,0x9ad0d5a3,0xf7696769,0x74e92f68,0x83dd09ba,0xd097451e,0xe86bd297,0xe9e7e907,0xc77f483,0x830d860d,0x286248c7,0x7b196b19,0xb718a719,0x4c992f19,0x97d305a6,0x3054c899,0x991b32d7,0x980f9867,0x2a58556f,0x157c2af6,0x9512ca91,0x9556953a,0xaae7957e,0x55735554,0xaa79d53f,0x55ab540b,0x565eab0f,0x5546a67d,0xa9e350b3,0xab16d409,0x551da9d5,0xae36a9bb,0x527752ce,0x51cf508f,0x5fbea35f,0x63fa82fd,0x8586b20d,0x4886a046,0xb76354a3,0x218d19c6,0x6532c616,0xd64258f1,0xeb035672,0x4d986b2c,0xf9b25b62,0x5764cec,0x2f761bfb,0x43534c7b,0xac66aa73,0x9d669166,0x1cd71e6,0xe0b1c60e,0x9cd939f0,
	0xce21ce4a,0x2d7bce0d,0x2d3f2d03,0xad6ad6b1,0xad7ead66,0xda7ada37,0xed62dabe,0xed16ed72,0x75efdaeb,0x9d409d70,0x3af59d2c,0x75f73a6d,0xba36ba09,0xba85ba51,0xeacf75db,0xeb63d33e,0xf509e979,0xe90ef5ca,0xf547d1dd,0xf5a3f46d,0xd6efea17,0x371fd1ef,0x36083430,0x316c1990,0xccf06338,0x6be86390,0xd1b86998,0xa8e184f0,0xba68cb11,0xa368c491,0x27a349d1,0x87ee26b8,0x7835e367,0xac663e17,0xac621c6f,0xdc65de34,0x62613c6b,0xa4db3269,0xe4c5a4c4,0x94cd29be,0xba669a6b,0x74d3b4d1,0x2cc8cccc,0xacd8acdc,0x398eecc9,0x9e6b9cd5,0xbcd9be61,0x858dfcdb,0xc59c45a5,0x8b368b4a,0x96da96c7,0x9605cb7c,0xacf7964d,0x563e5698,0x56f55679,0xd649acd7,0xeb2ceb5c,0x6c57d66d,0x9b571b50,0x9b3a9b0c,0xada8b6cb,0x76c4ad9b,0x14df6d9b,0x298f14e2,
	0x53f529d2,0xec31da6e,0xec0aecfc,0xed06ec9a,0xf661f639,0xf66df625,0x1ccc1dcf,0x3bd61d12,0x727c3b74,0x76cc7574,0xebbc706c,0xc334e1a4,0xc3a9c4a9,0x1b6757e9,0x9d73a167,0xa61735f3,0x12cb904b,0x17977697,0x8aa76d53,0x7a9f6ea7,0x1ae595cb,0xb5d2baee,0x9ba3f5d3,0xaddc9bbb,0xddd46dd9,0x7dc53dcc,0x2e4dfbab,0x5dc91b9b,0x41ef3dc3,0x58f7f0f4,0xe3cc71e2,0xa79ba79d,0xe790f3c2,0x5e765e2f,0xbdfb5e59,0x9cb34f1e,0x30d69e26,0xc4dbc86d,0xcbbde05b,0x3e3a607b,0xcefa653d,0xc63e03e9,0x7a9f023e,0xa6be879f,0x3ddf22be,0xd67e23be,0x77e997e,0x3bfb9efc,0x8ffdcbfa,0x79e1bff8,0x4ef116f2,0xc1016005,0xbd01e501,0xb3811a81,0x1f036b03,0xa5049904,0x8d053507,0x2f06bb05,0x42153e0c,0x590d090c,0x6f93721f,0x1bf217c0,0xdc3363f9,0xd19a2c67,
	0x9d08ca15,0xfa1b5a15,0x4c26cc30,0x8e11d61e,0xdf08cf86,0xa66f7e10,0xcce94cf9,0xe08808b6,0xb8886c47,0x9919691f,0x147df917,0xaa322a29,0xb451ea2e,0x74717453,0xacd62cf7,0x67fb59e4,0x8ff18ebd,0x3bb98ca9,0x72b66adb,0x6aac6776,0x636c526c,0x80b89bec,0x81b8aab8,0x45f88778,0x741297f1,0xed092413,0xd8c4e489,0xe3893dc4,0x6ce70273,0xe49c339a,0x7496549a,0xdce5ae63,0xe617b9a2,0x9ecbcee9,0x35593c77,0x387c9059,0x97129885,0x83e53fb2,0x2f504220,0xa7e54f18,0x131d4d6e,0x859b84f2,0xa2be454f,0xb151a28d,0x3c4ab8b7,0x569de692,0xdd38f695,0xfa437d3b,0x464f8668,0x933c675,0x792b524f,0xb9921991,0x564df323,0xacded644,0xd971d9cf,0x9c94392d,0x52a39c94,0xb496690d,0xb730d72b,0x664fb728,0xd932b2b,0x6de679e4,0x87931bca,0x23e4f7ca,
	0xdbf373f9,0x4c856c15,0x52b4a3d1,0x160e50ae,0x2ba82f4c,0x5b185b78,0xbd48b878,0x33d45a48,0xeafe66df,0x820b23f9,0x90bd7c16,0xb0b850b0,0x78b8d8b3,0x22e0f159,0x16bb45bf,0x17538b23,0x5d312e77,0x7864ba52,0x7dd2f069,0xb2cb68cb,0xe250fd96,0xf2555258,0xf2dc796a,0xd283528e,0x2b43a5a5,0x95345782,0xcbc994a9,0x5af4ae6e,0x611563b9,0xef556495,0x5bd5976a,0x172a7f56,0x70ac5f95,0xf8aea8ac,0xe6b846b0,0x5f4e57e2,0x79f57cd5,0xdedada6d,0xedcab74a,0xa4eb48eb,0xf7ac6eeb,0x4aafbf59,0xd5416abd,0xdf086d0,0x8df11bad,0x6d5f1be5,0xa174de4a,0x8ef56a7a,0xcacdb4cd,0x613503cd,0xcc5bed35,0xf2dbacb6,0xf6a336a1,0x5d7f9d7a,0xadfd56cb,0xd9beb7ab,0xbfd6da26,0xf37b77dd,0x151d830e,0x94efde3b,0x2bb5bcec,0xbd6b5778,0x6ef57d45,0xdd82eed2,
	0x1b621a8f,0x7ee6bfba,0x7747b8dd,0x8f9ec54f,0x77ba57b,0xebef45f6,0x6c6f746a,0xbfbfafdc,0x526d09b2,0x481e8d36,0x9be5703a,0x9bda6f80,0xb5779aed,0xe2a5a70,0xc1e541c2,0x7ca6df27,0xe850e37b,0xdcc3cea1,0x99dfcdc3,0x8f5b77f,0x2b7948eb,0x75bf3ad2,0x6da32dac,0xbda13da0,0xa38ce8ef,0x1d5e1d9d,0xffb7be47,0xe331ef7e,0x35c77563,0xa09e578f,0xf13d289d,0x9382e4f9,0xa764a7e3,0x3f4e9d9e,0xdc99d43d,0xfc4cf779,0x515d6b99,0x4367bd5d,0x173f9ecf,0xb74cee74,0xf3c9f75f,0x5d8fe7de,0xf470bcf0,0xdb62f722,0xad4bb725,0x473dae3d,0xe1fd707e,0x6f5baf48,0xcbf765eb,0xae3c57ed,0xeb4df474,0xd3efd13b,0xc06afa7f,0xf8d773d5,0x9f5d2ed7,0xc6efbd79,0x6eb71bec,0xb81cdd26,0xf8f5ba25,0x17edf676,0x4cee0a77,0x8f7a5ddc,0xbefcaf78,0x7eafdda,
	0x7fea0ffa,0x65b1feb4,0xf8e06dc0,0xcf60c060,0xef0f59c3,0x9e87090e,0xd3ff94fe,0x47d2e187,0x23d547cc,0x8f8d2346,0x1b1f1f9d,0xf2bd1a0d,0xe193ce64,0x13a7b2a7,0x567ecacf,0x73eb79ff,0xfddfe7ab,0xcf4bfbe2,0xf0d8fc58,0xcf8bf90b,0xa979aebf,0xabef72f3,0xc73aafa9,0xbc1fc723,0xf13d79ce,0xceadfca6,0xb8ef7ddb,0xc7dfbaef,0x28991fbd,0x50fe40fc,0x63fad1f3,0x4fd0a7c7,0x7ce73ef7,0xf72ffcfe,0x25fbf384,0x339fd2,0x63200000,0x4d5248,0x257a00,0x838000,0xfff900,0xe98000,0x307500,0x60ea00,0x983a00,0x926f1700,0x46c55f,0x49d30400,0x78544144,0xbf9ae4da,0x1447236b,0x3fb3bfc7,0xb61dd23,0x22410e14,0x1702d61b,0xe94e7502,0x1fd6b82e,0x5cc42a91,0x9d22bf93,0x1fc9b9c3,0x9b8083a1,0xeeb70114,0x93885422,0x7062b605,
	0x9593bd91,0xed5dbad8,0x9accd26a,0xeccdf8d1,0x706f2c1a,0xdefd0616,0xdef33ef7,0x8ef9bccc,0x2f1ce718,0x42f0b2e1,0xe20317ae,0x63184f64,0x9ec37f45,0x68fe37c9,0x7b040310,0x4f66bc4,0x7ee5730e,0x2b1c28bc,0x1e233ef0,0xbcb3e199,0x538e537b,0x48cfba8f,0xa0105620,0xa9215348,0xa8ceabfb,0x2d35e78e,0x8886390,0xd1e92cd5,0x1d7de22,0xa9600721,0xef125f3c,0x801e60eb,0x156022e8,0x68203a6c,0xe2b8952,0xbdea6917,0x6391c7ee,0x94e64488,0x136b392d,0xc2a5074d,0x4b6a1050,0x7b94c689,0x4ac6f32c,0xc003bce6,0xa803e005,0x600d7802,0xc01d4013,0xb608209b,0xdbfefdfa,0xc7df0c30,0x9fc57c71,0xf8e38ae8,0xf7c30c2a,0x6dff7efd,0x5b0410,0x9b9b08de,0xf0aa87c2,0x5a3e15c9,0xa9330a54,0x1a8855c7,0x34012f80,0x104e9d3a,0xbe07d145,0xa28a2be6,
	0x274e9d0f,0xb610d000,0x2d8c046b,0x17183cc1,0xb90a54,0xededed9c,0xfc3870ca,0x9dfdf7cd,0x38b060c1,0xce8d3d3d,0xebe2cece,0x53e5ebeb,0x468d7eac,0xdbdbdac3,0xf7f7f6f3,0xedbb76fd,0xbe745146,0xedfbbbbb,0x1cc5c5c5,0xa1600240,0x293c9ca4,0xc444a670,0x832bd292,0xa3b80170,0x9d87e8d1,0x71f9d9d,0xe8e2c183,0xc99fe8e8,0x63ae9264,0x9b366f39,0xe1e1e1f6,0xedbb76eb,0xff9f9f9e,0x7eb56ad4,0x90b1016,0x16c65126,0x4b1988b7,0xc0038a8d,0xdfebd7ab,0xd7af4000,0x20baf9b,0x49932600,0xe6f5ebda,0x7a6c2000,0xcadac752,0xbbef7284,0x2d7699a3,0xe005c209,0x5dd5ab55,0xc78f1800,0xac8bbac9,0xe9b086cc,0xec9bb311,0x1cc0072b,0xf5cccd,0x6bcf3c4,0x98d53c00,0xd995d30,0xa623d361,0x5a024b64,0xa975e329,0x62520f75,0x5349ee85,0x2cb536ae,
	0x2b6862c3,0x2e5d6530,0x1ad44631,0x4ac6c1ef,0xc94e5e97,0x1a2a267b,0xa443b74c,0x2d792b6a,0x54223329,0x634cc439,0xb2f49a04,0x35b1044b,0x63a28569,0x32af4d44,0xd174b53,0xa68118e3,0x20532f7c,0x95b374b1,0x9a614549,0xd4ccac19,0x523b34b2,0x15d760ed,0x1044ac92,0x50ad86d3,0x6530a96a,0x11cb16a6,0xb20e8c3a,0x28f12392,0x9217fe7f,0xdaac7f29,0x23ca0cf7,0xdc20a2f,0xd7594142,0xb76080b2,0x2473c202,0x9123329b,0x4219630b,0x25a48328,0xa106a482,0x996a50ae,0x4ee7b1c4,0x3622a5ad,0x2516a6e4,0x9200a59e,0xbfdbdbdb,0xdd63b532,0x8436679e,0x4d5144cd,0x2c645496,0xa2bcb883,0x786185fc,0x10410001,0xcc80bdac,0xaa9b086c,0x2129c404,0xa800d2db,0x3c62e612,0xa001f71e,0x9a56eddb,0x6adae6cd,0x69b366af,0x8addbb77,0x8afa2110,0x8545459e,
	0x7bc87bdc,0xab442ff4,0xb1b57802,0x7971b1b1,0xe6cbf979,0xcfd7e6e6,0xdcddd021,0xb5b9fcdc,0x6cddf5b5,0xb8019b36,0xe0077005,0xb168b3,0x753b4fbc,0xa248e1ff,0x2a402f9c,0xaf5aa602,0xd1a36bd7,0x56ad5de8,0xa99d6afb,0xaf4e9d35,0xf7d6ad5a,0x54e1861,0xb9801dc0,0xb1248880,0xb3a85eee,0x42c5faa5,0x7cc251ce,0xc7c7e73e,0x1a37bfc7,0x6db68f8d,0xca952b2f,0x2bf7df2b,0x6cfce14f,0x1c34fb36,0x3938ff0e,0xe0f5f939,0x74dde0e0,0x8a5bfd3a,0x41454440,0xca75ac5e,0x98a52b89,0xd659a4af,0xa2f9a22a,0x1cefd279,0x8f242362,0xd5ea44bf,0x891a3858,0x514b9f5e,0xa8c0d3b8,0x583b86e3,0x6751303d,0xd9b344ac,0x35899ccf,0x480e7610,0x1cc9806a,0x6244e79f,0x2477a565,0x66308c23,0xa2301b89,0x891cc864,0x284a0808,0x44f5a6a0,0xc733a811,0xb1604b3f,
	0x16ea9104,0x20b0c746,0x6420232,0x923b8cc9,0x2948e364,0x32c86d4a,0x33a95207,0x63c7a952,0x12b14229,0x20b4c48d,0x6b3a9a3a,0x7189d9a9,0xe81c3522,0x9d74e28f,0x25b51d40,0xa9128444,0x8435baa5,0xb288088a,0xcb16213d,0x3ceeb0cc,0xb80a1291,0x354a0ca6,0x3af48940,0x8c6bbe95,0x687d0708,0x537a6a99,0x61f75906,0xd719fca8,0xa68e2895,0x5e9285fa,0xc6568cd4,0x94b6b4f1,0xe5150667,0x187fabf,0x2f038ff2,0xff1c2fe6,0xd401000e,0x37ec8964,0xfbf8,0x45490000,0x42ae444e,0x8260,
};

zxzToast::zxzToast( CCNode* bg, CCNode* content, float duration ) :
	m_leftMargin(0),
	m_rightMargin(0),
	m_topMargin(0),
	m_bottomMargin(0),
	m_duration(duration),
	m_bg(NULL),
	m_content(NULL),
	m_dirty(false),
	m_useDefaultBg(false),
	m_useDefaultPosition(true){

		// get default background texture size
		//CCTexture2D* bgTex = CCTexture2D::makeRawPNG((const char*)_toast_bg_png, sizeof(_toast_bg_png) - 2);
		CCTexture2D *bgTex = new CCTexture2D();
		bgTex->initWithData((const char*)_toast_bg_png, kCCTexture2DPixelFormat_RGB888, 1, 1, CCSizeMake(64, 16));
		m_defaultBgWidth = bgTex->getContentSize().width;
		m_defaultBgHeight = bgTex->getContentSize().height;
		// set background and content
		setBackground(bg);
		setContent(content);

		// retain self
		retain();
}
zxzToast::~zxzToast()
{

}

zxzToast* zxzToast::create(CCNode* bg, CCNode* content, float duration) {
	zxzToast* t = new zxzToast(bg, content, duration);
	return (zxzToast*)t->autorelease();
}

zxzToast* zxzToast::create(CCNode* bg, const char* text, float duration) {
	CCLabelTTF* label = CCLabelTTF::create(text, "Arial",16);
	zxzToast* t = new zxzToast(bg, label, duration);
	return (zxzToast*)t->autorelease();
}

zxzToast* zxzToast::create(CCNode* content, float duration) {
	// create texture of default toast background
	CCTexture2D *bgTex = new CCTexture2D();
	bgTex->initWithData((const char*)_toast_bg_png, kCCTexture2DPixelFormat_RGB888, 1, 1, CCSizeMake(64, 16));
	CCSpriteBatchNode *batchNode=CCSpriteBatchNode::createWithTexture(bgTex);
	CCScale9Sprite *bg=CCScale9Sprite::create();

	CCRect fullRect = CCRectMake(0,0, 64, 16);
	CCRect insetRect = CCRectMake(24,24, 1, 1);
	bg->initWithBatchNode(batchNode,fullRect,insetRect);
	
	// create toast and set default margin
	zxzToast* t = new zxzToast(bg, content, duration);
	//t->setMargin(DP(15), DP(20), DP(20), DP(15));
	t->setMargin(15,20,20,15);
	t->m_useDefaultBg = true;
	return (zxzToast*)t->autorelease();
}

//zxzToast* zxzToast::create(const char* text, float duration) {
zxzToast* zxzToast::create(const char* backImageFile, const char* text, float duration) {
	// create texture of default toast background
	//CCTexture2D *bgTex = new CCTexture2D();
	//bgTex->initWithData((const char*)_toast_bg_png, kCCTexture2DPixelFormat_RGB888, 1, 1, CCSizeMake(64, 16));
	CCTexture2D *bgTex = new CCTexture2D();
	//CCImage *pImage = newCCImage(true);
	CCImage *pImage = new CCImage();

	if (pImage)
	{
		pImage->initWithImageFile(backImageFile);
	}
	else return NULL;

	bgTex->initWithImage(pImage);

	CCSpriteBatchNode *batchNode=CCSpriteBatchNode::createWithTexture(bgTex);
	CCScale9Sprite *bg=CCScale9Sprite::create();

	CCRect fullRect = CCRectMake(0,0, 64, 16);
	CCRect insetRect = CCRectMake(24,24, 1, 1);
	bg->initWithBatchNode(batchNode,fullRect,insetRect);

	// create label as content
	CCLabelTTF* label = CCLabelTTF::create(text, "Arial",16);
	// create toast and set default margin
	zxzToast* t = new zxzToast(bg, label, duration);
	//t->setMargin(DP(15), DP(20), DP(20), DP(15));
	t->setMargin(15, 20, 20, 15);
	t->m_useDefaultBg = true;

	CC_SAFE_DELETE(pImage);
	return (zxzToast*)t->autorelease();
}

void zxzToast::layout() {
	if(m_dirty) {
		// adjust bg size
		CCRect r=m_content->boundingBox();
		if(m_useDefaultBg) {
			m_bg->setContentSize(CCSizeMake(max(m_defaultBgWidth, r.size.width + m_leftMargin + m_rightMargin),max(m_defaultBgHeight, r.size.height + m_topMargin + m_bottomMargin)));
		} else {
			m_bg->setContentSize(CCSizeMake(r.size.width + m_leftMargin + m_rightMargin,r.size.height + m_topMargin + m_bottomMargin));
		}

		// set self size same as background, and position
		setContentSize(CCSizeMake(m_bg->getContentSize().width, m_bg->getContentSize().height));
		if(m_useDefaultPosition)
			setPosition(CCDirector::sharedDirector()->getVisibleSize().width/2,CCDirector::sharedDirector()->getVisibleSize().height/5);
		else
			setPosition(m_toastPositionX, m_toastPositionY);

		// set content and bg position
		m_content->setPosition(getContentSize().width/2,getContentSize().height/2);
		m_bg->setPosition(getContentSize().width/2,getContentSize().height/2);

		// clear flag
		m_dirty = false;
	}
}
//void zxzToast::clear() {
//	zxzToast::s_toastQueue->removeAllObjects();
//	zxzToast::s_toastQueue=NULL;
//}

void zxzToast::putToScene() {
	// get director
	CCDirector *d = CCDirector::sharedDirector();
	if(!d)		return;

	// get running scene
	CCScene* s = d->getRunningScene();
	if(!s)
		return;

	// perform layout
	layout();
	// set initial state
	//if(m_bg)
	//	m_bg->setAlpha(0);
	//if(m_content)
	//	m_content->setAlpha(0);

	// add to running scene
	//s->addChild(this, MAX_INT);
	s->addChild(this, 10000);

	// perform a fade out action after duration, so we need a sequence
	CCFiniteTimeAction*  a = CCSequence::create(
		CCFadeIn::create(0.7f),
		CCDelayTime::create(m_duration),
		CCFadeOut::create(0.7f),
		CCCallFuncND::create(this, callfuncND_selector(zxzToast::onToastFadedOut), (void*)this), 
		NULL);

	runAction(a);
}

void zxzToast::onToastFadedOut(CCNode* sender, void* data )
{
	// get director
	CCDirector *d = CCDirector::sharedDirector();
	if(!d)		return;

	// get running scene
	CCScene* s = d->getRunningScene();
	if(!s)		return;

	// remove toast
	zxzToast* t = (zxzToast*)data;
	s->removeChild(t, true);

	// if not immediately mode, need show next
	//if(!t->m_immediately) {
	//	// remove self from queue
	//	//s_toastQueue->erase(s_toastQueue->begin());
	//	zxzToast::s_toastQueue->removeObjectAtIndex(0);//...............................
	//	// has next?
	//	//if(s_toastQueue->begin() != s_toastQueue->end()) {
	//	//	zxzToast* next = *s_toastQueue->begin();
	//	//	next->putToScene();
	//	//}
	//	if(zxzToast::s_toastQueue->objectAtIndex(0) != zxzToast::s_toastQueue->lastObject()) {
	//		zxzToast* next = (zxzToast*)zxzToast::s_toastQueue->objectAtIndex(0);
	//		next->putToScene();
	//	}
	//}

	// release self
	t->autorelease();
}

void zxzToast::show() {
	//void zxzToast::show(bool immediately) {
	//m_immediately = immediately;
	//if(m_immediately) {
		putToScene();
	//} else {
	//	// lazy create
	//	if(!zxzToast::s_toastQueue)
	//		zxzToast::s_toastQueue =CCArray::create();

	//	// push this toast
	//	zxzToast::s_toastQueue->addObject(this);

	//	// if only this one, display it
	//	if(zxzToast::s_toastQueue->count()==1) {
	//		putToScene();
	//	}
	//}
}

void zxzToast::removeBackground() {
	// basic check
	if(!m_bg || !m_bg->getParent())
		return;

	// remove it
	removeChild(m_bg, true);
}

void zxzToast::addBackground() {
	// basic check
	if(!m_bg || m_bg->getParent())
		return;

	// add it with max z order
	addChild(m_bg);
}

void zxzToast::removeContent() {
	// basic check
	if(!m_content || !m_content->getParent())
		return;

	// remove it
	removeChild(m_content, true);
}

void zxzToast::addContent() {
	// basic check
	if(!m_content || m_content->getParent())
		return;

	// add it
	addChild(m_content, 1);
}

void zxzToast::setBackground(CCNode* bg) {
	// remove old bg from scene
	removeBackground();

	// save new bg
	m_bg = bg;
	addBackground();

	// set flag
	m_dirty = true;
	m_useDefaultBg = false;
}

void zxzToast::setContent(CCNode* c) {
	// remove old content node
	removeContent();

	// save new content node
	m_content = c;
	addContent();

	// set flag
	m_dirty = true;
}

void zxzToast::setMargin(float top, float left, float right, float bottom) {
	m_leftMargin = left;
	m_topMargin = top;
	m_rightMargin = right;
	m_bottomMargin = bottom;
	m_dirty = true;
}

void zxzToast::setToastPosition(float x, float y) {
	m_toastPositionX = x;
	m_toastPositionY = y;
	m_useDefaultPosition = false;
	m_dirty = true;
}

#endif // __zxzToast_h__
