.setcpu "65816"
.segment "CODE"
.org $2781
map_control_0d2781:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
