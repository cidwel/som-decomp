.setcpu "65816"
.segment "CODE"
.org $14D5
map_control_0e14d5:
    .byte $EB ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
