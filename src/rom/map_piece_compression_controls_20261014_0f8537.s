.setcpu "65816"
.segment "CODE"
.org $8537
map_control_0f8537:
    .byte $E9 ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E2 ; previous-row copy count
