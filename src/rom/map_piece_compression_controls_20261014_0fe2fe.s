.setcpu "65816"
.segment "CODE"
.org $E2FE
map_control_0fe2fe:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
