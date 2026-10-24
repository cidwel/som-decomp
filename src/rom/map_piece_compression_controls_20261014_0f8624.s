.setcpu "65816"
.segment "CODE"
.org $8624
map_control_0f8624:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E7 ; previous-row copy count
