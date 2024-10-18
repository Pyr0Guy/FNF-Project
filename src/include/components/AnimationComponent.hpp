#pragma once

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
    void Rotate(f32 amount);

    void SetAnimationSpeed(f32 speed);
    void SetScale(f32 scale);
    void SetRotation(f32 rotation);

    std::string GetCurrentAnimation() const;
    std::vector<std::string> GetAllAnimations() const;

    bool IsAnimationExsists(std::string& name) const;
private:
    s16 m_MaxFrames;
    f32 m_CurFrame;
    f32 m_AnimSpeed;
    f32 m_Scale;
    f32 m_Rotation;

    std::string m_curAnim;

    Rectangle m_CurFrameRect;
    AnimationList m_Animations;
    Vector2 m_Origin;

    Texture2D m_Texture;
};