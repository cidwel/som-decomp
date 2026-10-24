.setcpu "65816"
.segment "CODE"
.org $D93F
map_control_0ed93f:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
