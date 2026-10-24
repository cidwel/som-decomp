.setcpu "65816"
.segment "CODE"
.org $A7E2
map_control_0fa7e2:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
