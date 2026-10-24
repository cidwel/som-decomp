.setcpu "65816"
.segment "CODE"
.org $53DE
map_control_0e53de:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
