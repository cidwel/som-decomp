.setcpu "65816"
.segment "CODE"
.org $8788
map_control_0e8788:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E4 ; previous-row copy count
