.setcpu "65816"
.segment "CODE"
.org $31C7
map_control_0e31c7:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
