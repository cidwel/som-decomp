.setcpu "65816"
.segment "CODE"
.org $6726
map_control_0d6726:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
