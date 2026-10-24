.setcpu "65816"
.segment "CODE"
.org $AF1F
map_control_0eaf1f:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
