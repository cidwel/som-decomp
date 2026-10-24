.setcpu "65816"
.segment "CODE"
.org $3457
map_control_0d3457:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E7 ; previous-row copy count
