.setcpu "65816"
.segment "CODE"
.org $8A54
map_control_0e8a54:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E5 ; previous-row copy count
