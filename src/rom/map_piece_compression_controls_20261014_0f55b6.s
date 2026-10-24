.setcpu "65816"
.segment "CODE"
.org $55B6
map_control_0f55b6:
    .byte $E8 ; backreference distance high bits
    .byte $32 ; distance low bit/count
