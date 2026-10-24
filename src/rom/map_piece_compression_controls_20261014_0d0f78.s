.setcpu "65816"
.segment "CODE"
.org $0F78
map_control_0d0f78:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
