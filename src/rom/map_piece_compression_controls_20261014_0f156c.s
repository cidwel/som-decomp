.setcpu "65816"
.segment "CODE"
.org $156C
map_control_0f156c:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
