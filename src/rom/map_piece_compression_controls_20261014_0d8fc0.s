.setcpu "65816"
.segment "CODE"
.org $8FC0
map_control_0d8fc0:
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
