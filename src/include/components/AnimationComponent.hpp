#pragma once

#include <raylib.h>

#include "../types.hpp"

#include <vector>
#include <unordered_map>
#include <string>

class AnimationComponent
{
private:
    typedef std::unordered_map<std::string, std::vector<Rectangle>> AnimationList;

    void LoadAllAnimations(std::string XMLPath);

public:
    AnimationComponent(const char* filename, f32 animationSpeed);
    ~AnimationComponent();

    void Update();
    void Draw(const Vector2& pos);
    void Play(std::string animName);

    void SetAnimationSpeed(f32 speed);

    bool IsAnimationExsists(std::string& name) const;
private:
    s16 m_MaxFrames;
    f32 m_CurFrame;
    f32 m_AnimSpeed;

    std::string m_curAnim;

    Rectangle m_CurFrameRect;

    AnimationList m_Animations;

    Texture2D m_Texture;
};