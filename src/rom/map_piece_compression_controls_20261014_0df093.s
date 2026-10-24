.setcpu "65816"
.segment "CODE"
.org $F093
map_control_0df093:
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
