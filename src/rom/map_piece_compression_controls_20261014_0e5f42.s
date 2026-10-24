.setcpu "65816"
.segment "CODE"
.org $5F42
map_control_0e5f42:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
