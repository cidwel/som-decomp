.setcpu "65816"
.segment "CODE"
.org $F032
map_control_0df032:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
