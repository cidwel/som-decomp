.setcpu "65816"
.segment "CODE"
.org $3429
map_control_0f3429:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E3 ; previous-row copy count
