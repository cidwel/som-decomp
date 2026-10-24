.setcpu "65816"
.segment "CODE"
.org $1FEE
map_control_0c1fee:
    .byte $E0 ; previous-row copy escape
    .byte $A4 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $75 ; row-distance/count
