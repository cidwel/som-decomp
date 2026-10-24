.setcpu "65816"
.segment "CODE"
.org $1BAC
map_control_0f1bac:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
