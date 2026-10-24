.setcpu "65816"
.segment "CODE"
.org $9164
map_control_0f9164:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
