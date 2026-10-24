.setcpu "65816"
.segment "CODE"
.org $DD7D
map_control_0fdd7d:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
