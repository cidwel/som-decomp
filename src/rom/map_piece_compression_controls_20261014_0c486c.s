.setcpu "65816"
.segment "CODE"
.org $486C
map_control_0c486c:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
