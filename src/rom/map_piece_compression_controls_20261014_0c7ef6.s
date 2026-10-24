.setcpu "65816"
.segment "CODE"
.org $7EF6
map_control_0c7ef6:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
