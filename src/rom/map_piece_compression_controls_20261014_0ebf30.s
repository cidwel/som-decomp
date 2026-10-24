.setcpu "65816"
.segment "CODE"
.org $BF30
map_control_0ebf30:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
