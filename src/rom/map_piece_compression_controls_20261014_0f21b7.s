.setcpu "65816"
.segment "CODE"
.org $21B7
map_control_0f21b7:
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
