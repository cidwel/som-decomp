.setcpu "65816"
.segment "CODE"
.org $74D6
map_control_0c74d6:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
