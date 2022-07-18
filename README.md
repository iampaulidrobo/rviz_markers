# rviz_markers

 
The repo aims to give rviz plugin and markers demostration.
The package **display_gui** contain a widget based grid appearance enhancement.
The package **plugin_tutorial** contains markers.

To test the repo:
**Don't forget to source the workspace{source ~/{worspace_name}/install/setup.bash}** 

**display_gui**

In terminal-1:
```bash
   ros2 run display_gui display_gui 

```
Output:
![Screenshot from 2022-07-04 22-08-34](https://user-images.githubusercontent.com/22745024/177194787-460f9a82-a8d1-4ab5-b09c-f6ad70dc737c.png)
**plugin_tutorial**

Make sure to have "map" as fixed frame_id in the rviz2 visualization
In terminal-1:
```bash
    ros2 run plugin_tutorial basic_shapes

```
Output:
![Screenshot from 2022-07-04 22-09-18](https://user-images.githubusercontent.com/22745024/177194863-90e54b32-a82d-4cdd-88c1-dcd4d888c729.png)
In terminal-1:
```bash
    ros2 run plugin_tutorial points_and_line

```
Output:
![Screenshot from 2022-07-04 22-09-45](https://user-images.githubusercontent.com/22745024/177194906-aef87bbe-1973-4b67-a796-ef9b4eed5214.png)
In terminal-1:
```bash
   ros2 run plugin_tutorial interactive_marker

```
Use mouse to displace the CUBE
Output:
![Screenshot from 2022-07-04 22-11-10](https://user-images.githubusercontent.com/22745024/177194929-30c289d0-4009-4490-99d6-53c395223517.png)

In terminal-1:
```bash
    ros2 run plugin_tutorial interactive_marker_advance 

```
Use mouse to displace the CUBE
Output:
![Screenshot from 2022-07-04 22-11-31](https://user-images.githubusercontent.com/22745024/177194997-3dc8be8a-22d4-41cb-93c3-1038191652ac.png)
![Screenshot from 2022-07-04 22-11-32](https://user-images.githubusercontent.com/22745024/177195010-051db5f5-2f0f-4fdd-8132-8c1105b4fadf.png)
![Screenshot from 2022-07-04 22-11-34](https://user-images.githubusercontent.com/22745024/177195018-0d242452-2335-44ad-bcda-2e580bb78434.png)

**QT BASED SIMPLE GUI**
In terminal-1:
```bash
    ros2 run gui megui
```
Output:
![Screenshot from 2022-07-18 19-42-24](https://user-images.githubusercontent.com/22745024/179530831-8813d80c-7d84-425b-9715-d676e4d444d3.png)
![Screenshot from 2022-07-18 19-42-28](https://user-images.githubusercontent.com/22745024/179530852-075c06c6-db86-4790-a2c5-2680b67e0807.png)



