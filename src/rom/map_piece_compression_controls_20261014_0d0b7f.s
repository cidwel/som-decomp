.setcpu "65816"
.segment "CODE"
.org $0B7F
map_control_0d0b7f:
    .byte $E2 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
