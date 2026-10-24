.setcpu "65816"
.segment "CODE"
.org $77F7
map_control_0e77f7:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
