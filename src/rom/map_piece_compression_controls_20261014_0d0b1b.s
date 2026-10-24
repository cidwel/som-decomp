.setcpu "65816"
.segment "CODE"
.org $0B1B
map_control_0d0b1b:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E1 ; previous-row copy count
