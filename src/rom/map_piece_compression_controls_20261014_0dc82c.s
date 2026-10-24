.setcpu "65816"
.segment "CODE"
.org $C82C
map_control_0dc82c:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count
