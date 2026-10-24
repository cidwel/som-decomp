.setcpu "65816"
.segment "CODE"
.org $5517
map_control_0c5517:
    .byte $E9 ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E3 ; previous-row copy count
