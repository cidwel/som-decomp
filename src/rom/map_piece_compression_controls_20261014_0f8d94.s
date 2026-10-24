.setcpu "65816"
.segment "CODE"
.org $8D94
map_control_0f8d94:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E1 ; previous-row copy count
