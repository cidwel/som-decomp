.setcpu "65816"
.segment "CODE"
.org $CAA4
map_control_0fcaa4:
    .byte $E1 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
