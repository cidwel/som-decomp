.setcpu "65816"
.segment "CODE"
.org $7714
map_control_0f7714:
    .byte $E9 ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E1 ; previous-row copy count
