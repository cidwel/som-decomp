.setcpu "65816"
.segment "CODE"
.org $064E
map_control_0e064e:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
