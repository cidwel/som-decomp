.setcpu "65816"
.segment "CODE"
.org $F327
map_control_0cf327:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count
