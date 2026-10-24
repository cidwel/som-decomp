.setcpu "65816"
.segment "CODE"
.org $B22A
map_control_0fb22a:
    .byte $E6 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
