.setcpu "65816"
.segment "CODE"
.org $16C0
map_control_0f16c0:
    .byte $E3 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
