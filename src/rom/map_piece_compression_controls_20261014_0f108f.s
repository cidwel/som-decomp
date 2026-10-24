.setcpu "65816"
.segment "CODE"
.org $108F
map_control_0f108f:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
