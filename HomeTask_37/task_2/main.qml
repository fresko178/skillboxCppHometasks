import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtMultimedia 5.12

ApplicationWindow
{
  id: videoPlayer
  width: 1024
  height: 650
  visible: true
  title: qsTr("Media player")

  Column
  {
    Rectangle
    {
      id: screen
      color: "black"
      width: videoPlayer.width
      height: videoPlayer.height-60

      MediaPlayer
      {
          id: player
      }
      VideoOutput
      {
          anchors.fill: parent
          source: player
      }
    }

    Rectangle
    {
      id: control
      border.width: 1
      width: videoPlayer.width
      height: 30
      Row
      {
        spacing: 30
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left

        Slider
        {
          id: play
          width: videoPlayer.width * 0.75
          height: 30
          from: 0
          value: player.duration
          to: 100
          anchors.verticalCenter: parent.verticalCenter
        }

        Slider
        {
          id: voice
          width: videoPlayer.width * 0.2
          height: 30
          from: 0
          value: player.volume
          stepSize: 0.1
          to: 1
          anchors.verticalCenter: parent.verticalCenter
        }
      }
    }

    Rectangle
    {
      id: bottom
      border.color: "gray"
      border.width: 1
      width: videoPlayer.width
      height: 30
      Row
      {
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 10
        spacing: 10
        Button
        {
          text: "▶️"
          width: 40
          height: 30
          onClicked: { }
        }
        Button
        {
          text: "⏸️"
          width: 40
          height: 30
          onClicked: { }
        }
        Button
        {
          text: "⏹"
          width: 40
          height: 30
          onClicked: { }
        }
        Button
        {
          text: "⏪️"
          width: 40
          height: 30
          onClicked: { }
        }
        Button
        {
          text: "⏩️"
          width: 40
          height: 30
          onClicked: { }
        }
      }
    }
  }
}
