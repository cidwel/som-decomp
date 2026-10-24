.setcpu "65816"
.segment "CODE"
.org $85BB
map_control_0f85bb:
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
