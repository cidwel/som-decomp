.setcpu "65816"
.segment "CODE"
.org $B231
map_control_0fb231:
    .byte $ED ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
