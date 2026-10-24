.setcpu "65816"
.segment "CODE"
.org $323F
map_control_0f323f:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E2 ; previous-row copy count
