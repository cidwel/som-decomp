.setcpu "65816"
.segment "CODE"
.org $3047
map_control_0e3047:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
