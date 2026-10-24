.setcpu "65816"
.segment "CODE"
.org $C0D6
map_control_0ec0d6:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
