.setcpu "65816"
.segment "CODE"
.org $8B38
map_control_0e8b38:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
