.setcpu "65816"
.segment "CODE"
.org $EF60
map_control_0def60:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E3 ; previous-row copy count
