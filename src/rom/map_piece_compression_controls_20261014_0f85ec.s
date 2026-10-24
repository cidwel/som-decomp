.setcpu "65816"
.segment "CODE"
.org $85EC
map_control_0f85ec:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
