.setcpu "65816"
.segment "CODE"
.org $764E
map_control_0d764e:
    .byte $E0 ; previous-row copy escape
    .byte $CC ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $50 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
