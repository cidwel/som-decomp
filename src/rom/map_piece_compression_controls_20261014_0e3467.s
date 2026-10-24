.setcpu "65816"
.segment "CODE"
.org $3467
map_control_0e3467:
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
