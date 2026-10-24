.setcpu "65816"
.segment "CODE"
.org $D7CA
map_control_0dd7ca:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E2 ; previous-row copy count
