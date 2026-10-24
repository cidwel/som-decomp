.setcpu "65816"
.segment "CODE"
.org $AB2C
map_control_0fab2c:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E6 ; previous-row copy count
