#ifndef _TEXTCOMPONENT_H_
#define _TEXTCOMPONENT_H_

#include "../GuiComponent.h"
#include "../resources/Font.h"

class ThemeData;

// Used to display text.
// TextComponent::setSize(x, y) works a little differently than most components:
//  * (0, 0)                     - will automatically calculate a size that fits the text on one line (expand horizontally)
//  * (x != 0, 0)                - wrap text so that it does not reach beyond x. Will automatically calculate a vertical size (expand vertically).
//  * (x != 0, y <= fontHeight)  - will truncate text so it fits within this box.
class TextComponent : public GuiComponent
{
public:
	TextComponent(Window* window);
	TextComponent(Window* window, const std::string& text, std::shared_ptr<Font> font, Eigen::Vector3f pos = Eigen::Vector3f::Zero(), Eigen::Vector2f size = Eigen::Vector2f::Zero());

	void setFont(std::shared_ptr<Font> font);
	void onSizeChanged() override;
	void setText(const std::string& text);
	void setColor(unsigned int color);
	void setCentered(bool center); // Will horizontally center text.  Default is false.

	void render(const Eigen::Affine3f& parentTrans) override;

	std::string getValue() const override;
	void setValue(const std::string& value) override;

	unsigned char getOpacity() const override;
	void setOpacity(unsigned char opacity) override;
	
	std::shared_ptr<Font> getFont() const;

	virtual void applyTheme(const std::shared_ptr<ThemeData>& theme, const std::string& view, const std::string& element, unsigned int properties) override;

private:
	void calculateExtent();

	void onTextChanged();
	void onColorChanged();

	unsigned int mColor;
	std::shared_ptr<Font> mFont;
	Eigen::Matrix<bool, 1, 2> mAutoCalcExtent;
	std::string mText;
	std::shared_ptr<TextCache> mTextCache;
	bool mCentered;
};

#endif
