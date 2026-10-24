.setcpu "65816"
.segment "CODE"
.org $985B
map_control_0f985b:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
