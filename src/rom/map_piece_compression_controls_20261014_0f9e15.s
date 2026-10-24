.setcpu "65816"
.segment "CODE"
.org $9E15
map_control_0f9e15:
    .byte $E2 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
