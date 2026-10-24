.setcpu "65816"
.segment "CODE"
.org $2273
map_control_0d2273:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
