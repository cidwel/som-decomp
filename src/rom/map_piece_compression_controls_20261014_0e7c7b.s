.setcpu "65816"
.segment "CODE"
.org $7C7B
map_control_0e7c7b:
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
