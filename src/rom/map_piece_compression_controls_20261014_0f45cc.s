.setcpu "65816"
.segment "CODE"
.org $45CC
map_control_0f45cc:
    .byte $E0 ; previous-row copy escape
    .byte $52 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
