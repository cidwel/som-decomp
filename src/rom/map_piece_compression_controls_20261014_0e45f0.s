.setcpu "65816"
.segment "CODE"
.org $45F0
map_control_0e45f0:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E2 ; previous-row copy count
