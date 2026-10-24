.setcpu "65816"
.segment "CODE"
.org $64F2
map_control_0f64f2:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $54 ; distance low bit/count
