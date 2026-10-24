.setcpu "65816"
.segment "CODE"
.org $96CC
map_control_0f96cc:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
