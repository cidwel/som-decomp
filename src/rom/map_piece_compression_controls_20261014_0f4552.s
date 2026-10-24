.setcpu "65816"
.segment "CODE"
.org $4552
map_control_0f4552:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
