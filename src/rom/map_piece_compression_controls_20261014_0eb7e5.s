.setcpu "65816"
.segment "CODE"
.org $B7E5
map_control_0eb7e5:
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $ED ; row-distance/count
