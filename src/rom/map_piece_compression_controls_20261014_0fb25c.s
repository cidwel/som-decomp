.setcpu "65816"
.segment "CODE"
.org $B25C
map_control_0fb25c:
    .byte $E9 ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $42 ; row-distance/count
