.setcpu "65816"
.segment "CODE"
.org $5A92
map_control_0d5a92:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
