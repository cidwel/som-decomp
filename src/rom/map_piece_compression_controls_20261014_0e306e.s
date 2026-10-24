.setcpu "65816"
.segment "CODE"
.org $306E
map_control_0e306e:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
