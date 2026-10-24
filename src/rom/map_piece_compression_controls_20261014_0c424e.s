.setcpu "65816"
.segment "CODE"
.org $424E
map_control_0c424e:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
