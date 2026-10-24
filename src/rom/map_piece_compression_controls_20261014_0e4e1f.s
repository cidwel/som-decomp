.setcpu "65816"
.segment "CODE"
.org $4E1F
map_control_0e4e1f:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
