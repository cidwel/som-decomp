.setcpu "65816"
.segment "CODE"
.org $105F
map_control_0f105f:
    .byte $EE ; backreference distance high bits
    .byte $99 ; distance low bit/count
