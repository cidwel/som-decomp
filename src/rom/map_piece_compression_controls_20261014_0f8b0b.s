.setcpu "65816"
.segment "CODE"
.org $8B0B
map_control_0f8b0b:
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
    .byte $E1 ; previous-row copy count
