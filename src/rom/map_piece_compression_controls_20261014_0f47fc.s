.setcpu "65816"
.segment "CODE"
.org $47FC
map_control_0f47fc:
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
