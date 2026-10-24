.setcpu "65816"
.segment "CODE"
.org $3FC3
map_control_0f3fc3:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
