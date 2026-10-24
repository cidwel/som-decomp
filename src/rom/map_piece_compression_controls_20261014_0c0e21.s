.setcpu "65816"
.segment "CODE"
.org $0E21
map_control_0c0e21:
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $A9 ; row-distance/count
