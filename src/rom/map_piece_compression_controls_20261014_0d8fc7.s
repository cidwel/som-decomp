.setcpu "65816"
.segment "CODE"
.org $8FC7
map_control_0d8fc7:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E2 ; previous-row copy count
