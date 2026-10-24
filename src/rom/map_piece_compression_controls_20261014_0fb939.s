.setcpu "65816"
.segment "CODE"
.org $B939
map_control_0fb939:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $4B ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
