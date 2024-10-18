#pragma once

class SpriteComponent
{
public:
    SpriteComponent(const char* filepath);
    ~SpriteComponent();

    s32 GetWidth() const;
    s32 GetHeight() const;
    f32 GetScale() const;
    f32 GetRotation() const;

    void SetScale(f32 scale);
    void SetRotation(f32 rotation);

    void Rotate(f32 rotation);

    void ChangeTexture(Texture2D& texture);

    void Draw(const Vector2& pos);
private:
    Texture2D m_Texture;
    f32 m_Scale;
    f32 m_Rotation;
};