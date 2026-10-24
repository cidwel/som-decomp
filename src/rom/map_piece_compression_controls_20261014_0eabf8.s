.setcpu "65816"
.segment "CODE"
.org $ABF8
map_control_0eabf8:
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $67 ; row-distance/count
