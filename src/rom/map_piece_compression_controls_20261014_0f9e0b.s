.setcpu "65816"
.segment "CODE"
.org $9E0B
map_control_0f9e0b:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E5 ; previous-row copy count
