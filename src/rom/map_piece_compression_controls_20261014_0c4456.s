.setcpu "65816"
.segment "CODE"
.org $4456
map_control_0c4456:
    .byte $EF ; backreference distance high bits
    .byte $99 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
