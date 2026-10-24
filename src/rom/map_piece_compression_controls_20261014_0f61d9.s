.setcpu "65816"
.segment "CODE"
.org $61D9
map_control_0f61d9:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
