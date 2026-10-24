.setcpu "65816"
.segment "CODE"
.org $D9A4
map_control_0ed9a4:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
