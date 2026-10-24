.setcpu "65816"
.segment "CODE"
.org $79D9
map_control_0d79d9:
    .byte $E0 ; previous-row copy escape
    .byte $4D ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
