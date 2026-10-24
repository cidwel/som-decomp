.setcpu "65816"
.segment "CODE"
.org $45B4
map_control_0f45b4:
    .byte $E8 ; backreference distance high bits
    .byte $3D ; distance low bit/count
