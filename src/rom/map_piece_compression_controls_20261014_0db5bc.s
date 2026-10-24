.setcpu "65816"
.segment "CODE"
.org $B5BC
map_control_0db5bc:
    .byte $E8 ; backreference distance high bits
    .byte $3F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $DF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
