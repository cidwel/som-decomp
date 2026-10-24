.setcpu "65816"
.segment "CODE"
.org $1185
map_control_0c1185:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
