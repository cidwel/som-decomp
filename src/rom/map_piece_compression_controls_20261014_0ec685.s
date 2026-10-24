.setcpu "65816"
.segment "CODE"
.org $C685
map_control_0ec685:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
