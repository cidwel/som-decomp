.setcpu "65816"
.segment "CODE"
.org $25F7
map_control_0f25f7:
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
