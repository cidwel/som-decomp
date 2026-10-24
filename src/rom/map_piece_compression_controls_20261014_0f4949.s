.setcpu "65816"
.segment "CODE"
.org $4949
map_control_0f4949:
    .byte $E9 ; backreference distance high bits
    .byte $05 ; distance low bit/count
