.setcpu "65816"
.segment "CODE"
.org $8E95
map_control_0f8e95:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E3 ; previous-row copy count
