.setcpu "65816"
.segment "CODE"
.org $EA46
map_control_0eea46:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
