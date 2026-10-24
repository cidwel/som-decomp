.setcpu "65816"
.segment "CODE"
.org $28D2
map_control_0e28d2:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
