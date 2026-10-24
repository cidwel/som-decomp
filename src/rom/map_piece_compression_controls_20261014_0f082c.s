.setcpu "65816"
.segment "CODE"
.org $082C
map_control_0f082c:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
