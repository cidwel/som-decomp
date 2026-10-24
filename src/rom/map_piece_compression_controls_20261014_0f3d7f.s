.setcpu "65816"
.segment "CODE"
.org $3D7F
map_control_0f3d7f:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E1 ; previous-row copy count
