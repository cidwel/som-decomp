.setcpu "65816"
.segment "CODE"
.org $3888
map_control_0d3888:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
