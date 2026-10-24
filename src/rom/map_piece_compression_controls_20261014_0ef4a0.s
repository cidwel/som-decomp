.setcpu "65816"
.segment "CODE"
.org $F4A0
map_control_0ef4a0:
    .byte $E0 ; previous-row copy escape
    .byte $B9 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7A ; row-distance/count
