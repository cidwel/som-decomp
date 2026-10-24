.setcpu "65816"
.segment "CODE"
.org $79A7
map_control_0f79a7:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
