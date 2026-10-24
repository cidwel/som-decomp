.setcpu "65816"
.segment "CODE"
.org $19A8
map_control_0f19a8:
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
