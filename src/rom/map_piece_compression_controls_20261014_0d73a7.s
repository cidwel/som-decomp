.setcpu "65816"
.segment "CODE"
.org $73A7
map_control_0d73a7:
    .byte $E0 ; previous-row copy escape
    .byte $B4 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $38 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $3E ; row-distance/count
