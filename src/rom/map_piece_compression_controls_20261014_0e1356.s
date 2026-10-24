.setcpu "65816"
.segment "CODE"
.org $1356
map_control_0e1356:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $4F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
