.setcpu "65816"
.segment "CODE"
.org $F5FB
map_control_0cf5fb:
    .byte $E8 ; backreference distance high bits
    .byte $29 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $2C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $62 ; row-distance/count
