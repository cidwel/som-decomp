.setcpu "65816"
.segment "CODE"
.org $ABA3
map_control_0daba3:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
