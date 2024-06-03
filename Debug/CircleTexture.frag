#version 330

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
in vec4 fragColor;

// Input uniform values
uniform sampler2D texture0;
uniform vec4 colDiffuse;

uniform vec2 center;
uniform float radius;
uniform vec2 renderSize;

// Output fragment color
out vec4 finalColor;

// NOTE: Add here your custom variables

void main()
{
	vec2 NNfragTexCoord = fragTexCoord * renderSize;
	float L = length(center - NNfragTexCoord);
	
	if (L <= radius)	finalColor = texture(texture0, fragTexCoord) * fragColor;
	else	finalColor = vec4(.0);
}
