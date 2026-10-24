.setcpu "65816"
.segment "CODE"
.org $4CBB
map_control_0c4cbb:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E1 ; previous-row copy count
