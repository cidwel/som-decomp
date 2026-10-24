.setcpu "65816"
.segment "CODE"
.org $5423
map_control_0f5423:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E3 ; previous-row copy count
