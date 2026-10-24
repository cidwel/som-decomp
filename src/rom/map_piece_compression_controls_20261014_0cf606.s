.setcpu "65816"
.segment "CODE"
.org $F606
map_control_0cf606:
    .byte $E8 ; backreference distance high bits
    .byte $29 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $B3 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $63 ; row-distance/count
