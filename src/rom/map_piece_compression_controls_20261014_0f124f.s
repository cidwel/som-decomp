.setcpu "65816"
.segment "CODE"
.org $124F
map_control_0f124f:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
