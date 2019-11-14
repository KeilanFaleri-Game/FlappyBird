#version 120

attribute vec2 a_Position;
attribute vec2 a_UV;

uniform vec2 u_ObjectTranslation;
uniform vec2 u_CameraTranslation;
uniform vec2 u_ProjectionScale;

varying vec2 v_UV;

void main()
{
    vec2 pos = a_Position;

    pos += u_ObjectTranslation;
    pos += u_CameraTranslation;
    pos *= u_ProjectionScale;

    gl_Position = vec4( pos, 0, 1 );

    v_UV = a_UV;
}
