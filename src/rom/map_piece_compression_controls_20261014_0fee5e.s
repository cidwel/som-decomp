.setcpu "65816"
.segment "CODE"
.org $EE5E
map_control_0fee5e:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
