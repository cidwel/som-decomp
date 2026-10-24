.setcpu "65816"
.segment "CODE"
.org $CC11
map_control_0ecc11:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $56 ; row-distance/count
