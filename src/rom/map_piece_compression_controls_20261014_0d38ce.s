.setcpu "65816"
.segment "CODE"
.org $38CE
map_control_0d38ce:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
