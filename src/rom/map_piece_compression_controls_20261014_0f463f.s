.setcpu "65816"
.segment "CODE"
.org $463F
map_control_0f463f:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $67 ; distance low bit/count
