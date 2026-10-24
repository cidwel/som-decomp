.setcpu "65816"
.segment "CODE"
.org $B5EC
map_control_0db5ec:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
