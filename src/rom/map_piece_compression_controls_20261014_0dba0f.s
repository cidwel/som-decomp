.setcpu "65816"
.segment "CODE"
.org $BA0F
map_control_0dba0f:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
