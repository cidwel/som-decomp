.setcpu "65816"
.segment "CODE"
.org $12CC
map_control_0f12cc:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
