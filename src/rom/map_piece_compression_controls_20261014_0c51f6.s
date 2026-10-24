.setcpu "65816"
.segment "CODE"
.org $51F6
map_control_0c51f6:
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
