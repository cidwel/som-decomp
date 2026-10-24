.setcpu "65816"
.segment "CODE"
.org $DE58
map_control_0fde58:
    .byte $E7 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
