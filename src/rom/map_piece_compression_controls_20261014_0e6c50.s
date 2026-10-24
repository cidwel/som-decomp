.setcpu "65816"
.segment "CODE"
.org $6C50
map_control_0e6c50:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
