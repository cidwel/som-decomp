.setcpu "65816"
.segment "CODE"
.org $37AB
map_control_0d37ab:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
