.setcpu "65816"
.segment "CODE"
.org $49F7
map_control_0c49f7:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
