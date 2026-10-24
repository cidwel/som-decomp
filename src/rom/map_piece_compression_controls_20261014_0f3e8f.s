.setcpu "65816"
.segment "CODE"
.org $3E8F
map_control_0f3e8f:
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E1 ; previous-row copy count
