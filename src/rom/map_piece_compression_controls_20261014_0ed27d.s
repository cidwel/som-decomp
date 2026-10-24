.setcpu "65816"
.segment "CODE"
.org $D27D
map_control_0ed27d:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
