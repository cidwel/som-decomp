.setcpu "65816"
.segment "CODE"
.org $F05A
map_control_0df05a:
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
