.setcpu "65816"
.segment "CODE"
.org $7DFD
map_control_0c7dfd:
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
