.setcpu "65816"
.segment "CODE"
.org $D412
map_control_0ed412:
    .byte $EF ; backreference distance high bits
    .byte $18 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $4A ; row-distance/count
