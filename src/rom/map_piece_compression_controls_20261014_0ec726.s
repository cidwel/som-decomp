.setcpu "65816"
.segment "CODE"
.org $C726
map_control_0ec726:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
