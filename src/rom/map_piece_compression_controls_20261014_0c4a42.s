.setcpu "65816"
.segment "CODE"
.org $4A42
map_control_0c4a42:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
