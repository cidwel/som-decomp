.setcpu "65816"
.segment "CODE"
.org $9BA7
map_control_0f9ba7:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
