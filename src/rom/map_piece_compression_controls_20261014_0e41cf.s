.setcpu "65816"
.segment "CODE"
.org $41CF
map_control_0e41cf:
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E7 ; previous-row copy count
