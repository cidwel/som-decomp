.setcpu "65816"
.segment "CODE"
.org $926E
map_control_0d926e:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
