.setcpu "65816"
.segment "CODE"
.org $4727
map_control_0c4727:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E1 ; previous-row copy count
