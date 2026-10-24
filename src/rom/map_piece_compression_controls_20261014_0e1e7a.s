.setcpu "65816"
.segment "CODE"
.org $1E7A
map_control_0e1e7a:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
