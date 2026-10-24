.setcpu "65816"
.segment "CODE"
.org $8E6D
map_control_0f8e6d:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E3 ; previous-row copy count
