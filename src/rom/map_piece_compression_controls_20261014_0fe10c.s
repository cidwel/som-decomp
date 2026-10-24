.setcpu "65816"
.segment "CODE"
.org $E10C
map_control_0fe10c:
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
