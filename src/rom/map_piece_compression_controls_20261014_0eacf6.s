.setcpu "65816"
.segment "CODE"
.org $ACF6
map_control_0eacf6:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
