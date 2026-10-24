.setcpu "65816"
.segment "CODE"
.org $1007
map_control_0f1007:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
