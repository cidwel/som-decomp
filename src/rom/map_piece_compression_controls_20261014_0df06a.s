.setcpu "65816"
.segment "CODE"
.org $F06A
map_control_0df06a:
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
