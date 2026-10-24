.setcpu "65816"
.segment "CODE"
.org $4D83
map_control_0c4d83:
    .byte $ED ; backreference distance high bits
    .byte $9D ; distance low bit/count
