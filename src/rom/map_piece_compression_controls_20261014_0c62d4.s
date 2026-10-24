.setcpu "65816"
.segment "CODE"
.org $62D4
map_control_0c62d4:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
