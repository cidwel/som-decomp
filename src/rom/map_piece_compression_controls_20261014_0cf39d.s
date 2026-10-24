.setcpu "65816"
.segment "CODE"
.org $F39D
map_control_0cf39d:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E5 ; previous-row copy count
