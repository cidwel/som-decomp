.setcpu "65816"
.segment "CODE"
.org $363E
map_control_0e363e:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
