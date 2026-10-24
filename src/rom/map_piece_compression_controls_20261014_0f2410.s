.setcpu "65816"
.segment "CODE"
.org $2410
map_control_0f2410:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $58 ; row-distance/count
