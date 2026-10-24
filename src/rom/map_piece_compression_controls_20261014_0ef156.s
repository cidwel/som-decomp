.setcpu "65816"
.segment "CODE"
.org $F156
map_control_0ef156:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $37 ; distance low bit/count
    .byte $E4 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $3A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3C ; row-distance/count
