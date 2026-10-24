.setcpu "65816"
.segment "CODE"
.org $86CB
map_control_0d86cb:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
