#version 330

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
in vec4 fragColor;

// Input uniform values
uniform sampler2D texture0;
uniform vec4 colDiffuse;

uniform vec2 center;//0/0
uniform float radius;//50
uniform vec2 renderSize;//1000/1000

// Output fragment color
out vec4 finalColor;

// NOTE: Add here your custom variables

//vec2 center = vec2(.0);
//float radius = 100.;
//vec2 renderSize = vec2(640.0);

void main()
{
	vec2 NNfragTexCoord = fragTexCoord * renderSize;
	float L = length(center - NNfragTexCoord);
	//L = length(NNfragTexCoord);
	
	if (L <= radius)	finalColor = texture(texture0, fragTexCoord) * fragColor;
	else	finalColor = vec4(.0);
}
