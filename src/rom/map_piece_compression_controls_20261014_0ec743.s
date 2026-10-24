.setcpu "65816"
.segment "CODE"
.org $C743
map_control_0ec743:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
