.setcpu "65816"
.segment "CODE"
.org $EF4F
map_control_0def4f:
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E3 ; previous-row copy count
