.setcpu "65816"
.segment "CODE"
.org $793B
map_control_0c793b:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
