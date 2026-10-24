.setcpu "65816"
.segment "CODE"
.org $623C
map_control_0e623c:
    .byte $EF ; backreference distance high bits
    .byte $19 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
