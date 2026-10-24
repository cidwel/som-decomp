.setcpu "65816"
.segment "CODE"
.org $B679
map_control_0fb679:
    .byte $ED ; backreference distance high bits
    .byte $09 ; distance low bit/count
