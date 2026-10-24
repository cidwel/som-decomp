.setcpu "65816"
.segment "CODE"
.org $F0E8
map_control_0df0e8:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
