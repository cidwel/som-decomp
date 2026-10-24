.setcpu "65816"
.segment "CODE"
.org $E259
map_control_0fe259:
    .byte $F1 ; progressive-copy count
    .byte $EA ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
