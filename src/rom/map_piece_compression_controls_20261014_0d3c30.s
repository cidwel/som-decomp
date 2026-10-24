.setcpu "65816"
.segment "CODE"
.org $3C30
map_control_0d3c30:
    .byte $E2 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
