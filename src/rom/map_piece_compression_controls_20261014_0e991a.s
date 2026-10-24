.setcpu "65816"
.segment "CODE"
.org $991A
map_control_0e991a:
    .byte $E8 ; backreference distance high bits
    .byte $B0 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
