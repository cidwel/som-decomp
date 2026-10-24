.setcpu "65816"
.segment "CODE"
.org $C891
map_control_0ec891:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
