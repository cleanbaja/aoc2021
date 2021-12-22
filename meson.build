project(
	'advc2021', 
	'cpp', 
	version: '0.1.0', 
	license: 'MIT',
	default_options: ['cpp_std=c++17', 'warning_level=3']
)

if get_option('day') == 0
  # Build all the solutions
  solutions = ['days/day1', 'days/day2', 'days/day3']
  foreach dir : solutions
    subdir(dir)
  endforeach
else
  # Build a specific solution
  dir_name = 'days/day' + get_option('day').to_string()
  subdir(dir_name)
endif


