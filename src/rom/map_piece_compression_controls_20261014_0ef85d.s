.setcpu "65816"
.segment "CODE"
.org $F85D
map_control_0ef85d:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
