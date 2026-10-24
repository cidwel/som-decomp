.setcpu "65816"
.segment "CODE"
.org $911C
map_control_0f911c:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
