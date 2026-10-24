.setcpu "65816"
.segment "CODE"
.org $8859
map_control_0e8859:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
