.setcpu "65816"
.segment "CODE"
.org $CC0A
map_control_0ecc0a:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
    .byte $E5 ; previous-row copy count
