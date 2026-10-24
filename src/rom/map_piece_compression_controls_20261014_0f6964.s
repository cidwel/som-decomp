.setcpu "65816"
.segment "CODE"
.org $6964
map_control_0f6964:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
