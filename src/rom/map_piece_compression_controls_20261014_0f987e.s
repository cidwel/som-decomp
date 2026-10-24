.setcpu "65816"
.segment "CODE"
.org $987E
map_control_0f987e:
    .byte $EE ; backreference distance high bits
    .byte $0B ; distance low bit/count
