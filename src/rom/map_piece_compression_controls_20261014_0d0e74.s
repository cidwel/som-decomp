.setcpu "65816"
.segment "CODE"
.org $0E74
map_control_0d0e74:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E1 ; previous-row copy count
