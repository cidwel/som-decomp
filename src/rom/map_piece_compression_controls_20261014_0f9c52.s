.setcpu "65816"
.segment "CODE"
.org $9C52
map_control_0f9c52:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
