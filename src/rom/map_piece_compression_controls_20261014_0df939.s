.setcpu "65816"
.segment "CODE"
.org $F939
map_control_0df939:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
