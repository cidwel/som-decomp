.setcpu "65816"
.segment "CODE"
.org $7B88
map_control_0e7b88:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
