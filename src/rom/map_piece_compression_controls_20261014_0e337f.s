.setcpu "65816"
.segment "CODE"
.org $337F
map_control_0e337f:
    .byte $E3 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
