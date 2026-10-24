.setcpu "65816"
.segment "CODE"
.org $3E98
map_control_0d3e98:
    .byte $E2 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
