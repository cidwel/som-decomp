.setcpu "65816"
.segment "CODE"
.org $F13E
map_control_0ef13e:
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $34 ; row-distance/count
