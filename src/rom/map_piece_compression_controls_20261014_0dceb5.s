.setcpu "65816"
.segment "CODE"
.org $CEB5
map_control_0dceb5:
    .byte $E3 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
