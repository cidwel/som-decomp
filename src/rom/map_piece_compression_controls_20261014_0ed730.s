.setcpu "65816"
.segment "CODE"
.org $D730
map_control_0ed730:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $5E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
