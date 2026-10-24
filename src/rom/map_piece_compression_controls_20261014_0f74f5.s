.setcpu "65816"
.segment "CODE"
.org $74F5
map_control_0f74f5:
    .byte $F1 ; progressive-copy count
    .byte $EA ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
