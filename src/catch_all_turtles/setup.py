from setuptools import setup

package_name = 'catch_all_turtles'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='robot',
    maintainer_email='veam1011@hs-karlsruhe.de',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "turtlesim_controller = catch_all_turtles.turtlesim_controller:main",
            "turtle_spwaner = catch_all_turtles.turtle_spwaner:main"
        ],
    },
)
