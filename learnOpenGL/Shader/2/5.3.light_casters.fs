#version 330 core

struct Material
{
	sampler2D diffuse;
	sampler2D specular;
	float shiness;
};
struct Light{
	vec3 position;
	vec3 direction;
	float cutOff;
	float outerCutOff;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

	float constant;
	float linear;
	float quadratic;
};

uniform Light light;
uniform Material material;
uniform vec3 lightColor;
uniform vec3 objectColor;
uniform vec3 viewPos;
uniform vec3 lightPos;

in vec2 TexCoords;
in vec3 FragPos;
in vec3 Normal;

out vec4 FragColor;

void main()
{
	vec3 lightDir = normalize(lightPos-FragPos);
	float theta = dot(lightDir,normalize(-light.direction));

	if(theta > light.cutOff)
	{
		//环境光
	vec3 ambient = light.ambient*texture(material.diffuse,TexCoords).rgb;

	//漫反射
	 vec3 norm = normalize(Normal);
    	
    	float diff = max(dot(norm, lightDir), 0.0);
    	vec3 diffuse = light.diffuse * diff * texture(material.specular,TexCoords).rgb;

	//镜面光

	vec3 viewDir = normalize(viewPos - FragPos);
    	vec3 reflectDir = reflect(-lightDir, norm);  
    	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shiness);
    	vec3 specular = light.specular * (spec * texture(material.specular, TexCoords).rgb); 
	//衰减度
	float distance = length(light.position-FragPos);
	float attenuation = 1.0/(light.constant+light.linear*distance+light.quadratic*(distance*distance));

	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;
	
	vec3 result = (ambient+diffuse+specular);
	FragColor = vec4(result,1.0f);
	}
	else 
    {
        // else, use ambient light so scene isn't completely dark outside the spotlight.
        FragColor = vec4(light.ambient * texture(material.diffuse, TexCoords).rgb, 1.0);
    }

}