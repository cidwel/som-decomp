.setcpu "65816"
.segment "CODE"
.org $28D6
map_control_0c28d6:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $23 ; distance low bit/count
