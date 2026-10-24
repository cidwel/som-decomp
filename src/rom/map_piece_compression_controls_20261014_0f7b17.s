.setcpu "65816"
.segment "CODE"
.org $7B17
map_control_0f7b17:
    .byte $DA ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
