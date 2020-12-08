#pragma once

class Placeholder final
{
public:
	static void run();

public:
	explicit Placeholder() = delete;
	~Placeholder() = delete;
	Placeholder(const Placeholder&) = delete;
	Placeholder& operator=(const Placeholder&) = delete;	
};
