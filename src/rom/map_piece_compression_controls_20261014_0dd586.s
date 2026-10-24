.setcpu "65816"
.segment "CODE"
.org $D586
map_control_0dd586:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $B1 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $53 ; row-distance/count
