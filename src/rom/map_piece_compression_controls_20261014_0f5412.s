.setcpu "65816"
.segment "CODE"
.org $5412
map_control_0f5412:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E4 ; previous-row copy count
