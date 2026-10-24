.setcpu "65816"
.segment "CODE"
.org $4436
map_control_0f4436:
    .byte $EF ; backreference distance high bits
    .byte $94 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $43 ; row-distance/count
