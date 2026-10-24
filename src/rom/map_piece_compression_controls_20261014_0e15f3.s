.setcpu "65816"
.segment "CODE"
.org $15F3
map_control_0e15f3:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
