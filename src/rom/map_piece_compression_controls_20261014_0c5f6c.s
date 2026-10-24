.setcpu "65816"
.segment "CODE"
.org $5F6C
map_control_0c5f6c:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
