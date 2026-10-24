.setcpu "65816"
.segment "CODE"
.org $6D20
map_control_0f6d20:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
    .byte $E2 ; previous-row copy count
