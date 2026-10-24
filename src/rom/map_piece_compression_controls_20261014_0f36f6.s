.setcpu "65816"
.segment "CODE"
.org $36F6
map_control_0f36f6:
    .byte $CC ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
