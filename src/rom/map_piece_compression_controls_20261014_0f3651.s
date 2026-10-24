.setcpu "65816"
.segment "CODE"
.org $3651
map_control_0f3651:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $23 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
