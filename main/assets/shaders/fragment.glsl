#version 330 core
out vec4 FragColor;

in vec3 color;
in vec2 texCoords;
uniform sampler2D u_texture;

void main() {
	vec4 texColor = texture(u_texture, texCoords);
	FragColor = vec4(texColor.rgb, 1.0);
}
