.setcpu "65816"
.segment "CODE"
.org $8B78
map_control_0c8b78:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E7 ; previous-row copy count
