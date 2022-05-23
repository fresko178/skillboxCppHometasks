import QtQuick 2.11
import QtQuick.Window 2.11

Window
{
  id: root
  width: 640
  height: 480
  visible: true
  title: qsTr("Make transition 2")

  Rectangle {
    id: scene
    anchors.fill: parent
    state: "LeftState"

    Rectangle {
      id: leftRectangle
      x: 100
      y: 200
      color: "lightgrey"
      width: 100
      height: 100
      border.color: "black"
      border.width: 3
      radius: 5
      Text {
        id: leftText
        text: qsTr(" move")
      }
      MouseArea {
        anchors.fill: parent
        onClicked: {
          ball.x += 30
          if (ball.x >= rightRectangle.x) {
            scene.state = "LeftState"
          } else {
            scene.state = "OtherState"
          }
        }
      }
    }

    Rectangle {
      id: rightRectangle
      x: 300
      y: 200
      color: "lightgrey"
      width: 100
      height: 100
      border.color: "black"
      border.width: 3
      radius: 5
      Text {
        id: rightText
        text: qsTr(" return")
      }
      MouseArea {
        anchors.fill: parent
        onClicked: scene.state = "LeftState"
      }
    }
    Rectangle {
      id: ball
      x: leftRectangle.x + 5
      y: leftRectangle.y + 5
      color: "darkgreen"
      width: leftRectangle.width - 10
      height: leftRectangle.height - 10
      radius: width / 2
    }

    states: [
      State {
        name: "OtherState"
        PropertyChanges {
          target: ball
          x: ball.x
        }
      },
      State {
        name: "LeftState"
        PropertyChanges {
          target: ball
          x: leftRectangle.x + 5
        }
      }
    ]

    transitions: [
      Transition {
        from: "OtherState"
        to: "LeftState"
        NumberAnimation {
          properties: "x,y"
          duration: 500
          easing.type: Easing.OutBounce
        }
      }
    ]
  }
}
