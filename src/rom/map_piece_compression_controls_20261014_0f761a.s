.setcpu "65816"
.segment "CODE"
.org $761A
map_control_0f761a:
    .byte $E5 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
