.setcpu "65816"
.segment "CODE"
.org $F1B4
map_control_0ef1b4:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $3B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
