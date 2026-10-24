.setcpu "65816"
.segment "CODE"
.org $8549
map_control_0c8549:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
