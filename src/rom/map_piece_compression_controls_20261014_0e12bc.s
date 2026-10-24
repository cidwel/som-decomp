.setcpu "65816"
.segment "CODE"
.org $12BC
map_control_0e12bc:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $37 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $71 ; distance low bit/count
