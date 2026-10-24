.setcpu "65816"
.segment "CODE"
.org $BC14
map_control_0dbc14:
    .byte $E0 ; previous-row copy escape
    .byte $BC ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $40 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $57 ; row-distance/count
