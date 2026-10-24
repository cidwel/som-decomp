.setcpu "65816"
.segment "CODE"
.org $8E17
map_control_0f8e17:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E6 ; previous-row copy count
