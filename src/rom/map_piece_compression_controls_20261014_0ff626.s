.setcpu "65816"
.segment "CODE"
.org $F626
map_control_0ff626:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
