.setcpu "65816"
.segment "CODE"
.org $7D6D
map_control_0c7d6d:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $24 ; distance low bit/count
    .byte $E6 ; previous-row copy count
