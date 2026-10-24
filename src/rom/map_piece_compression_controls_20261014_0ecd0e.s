.setcpu "65816"
.segment "CODE"
.org $CD0E
map_control_0ecd0e:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
