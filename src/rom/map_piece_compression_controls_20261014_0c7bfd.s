.setcpu "65816"
.segment "CODE"
.org $7BFD
map_control_0c7bfd:
    .byte $E0 ; previous-row copy escape
    .byte $37 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E4 ; previous-row copy count
