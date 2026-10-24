.setcpu "65816"
.segment "CODE"
.org $47F4
map_control_0c47f4:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
