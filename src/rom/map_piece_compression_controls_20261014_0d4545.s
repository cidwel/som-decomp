.setcpu "65816"
.segment "CODE"
.org $4545
map_control_0d4545:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
