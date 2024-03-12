#pragma once

#include "RNOH/arkui/ArkUINode.h"
#include "EventEmitters.h"
namespace rnoh {

    class SwiperNodeDelegate {
    public:
        virtual ~SwiperNodeDelegate() = default;
    
        virtual void onPageSelected(double pageIndex){};
    
        virtual void onPageScroll(facebook::react::RNCViewPagerEventEmitter::OnPageScroll pageScroll){};
    
        virtual void onPageScrollStateChanged(facebook::react::RNCViewPagerEventEmitter::OnPageScrollStateChanged value){};
    
        virtual bool getScrollEnabled(){
          return true;
        };
    
        virtual bool getNativeLock(){
          return false;
        }; 
    
        virtual int getLayoutMetricsWidth(){
          return 0;   
        }
    };

    class SwiperNode : public ArkUINode {
    protected:
        SwiperNodeDelegate *m_swiperNodeDelegate;

    public:
        SwiperNode();

        void setSwiperNodeDelegate(SwiperNodeDelegate *swiperNodeDelegate);

        void insertChild(ArkUINode &child, std::size_t index);

        void removeChild(ArkUINode &child);

        void onNodeEvent(ArkUI_NodeEvent *event) override;

        SwiperNode &setIndex(int const &initialPage);
    
        SwiperNode &setVertical(std::string const &orientation);
    
        SwiperNode &setDirection(std::string const &layoutDirection);
    
        SwiperNode &setItemSpace(int const &pageMargin);
    
        SwiperNode &setCachedCount(int const &offscreenPageLimit);
    
        SwiperNode &setDisableSwipe(bool const &scrollEnabled);
    
        SwiperNode &setEffectMode(std::string const &effectMode);
    
        SwiperNode &setLoop(bool const &loop);
    
        SwiperNode &setDuration(int const &duration);
    
        SwiperNode &setIndicator(bool const &indicator);
    
    };

} // namespace rnoh