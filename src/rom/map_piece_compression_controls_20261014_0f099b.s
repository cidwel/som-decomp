.setcpu "65816"
.segment "CODE"
.org $099B
map_control_0f099b:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
