.setcpu "65816"
.segment "CODE"
.org $85DA
map_control_0f85da:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
