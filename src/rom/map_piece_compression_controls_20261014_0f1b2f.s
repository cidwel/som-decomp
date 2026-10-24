.setcpu "65816"
.segment "CODE"
.org $1B2F
map_control_0f1b2f:
    .byte $E0 ; previous-row copy escape
    .byte $A5 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
