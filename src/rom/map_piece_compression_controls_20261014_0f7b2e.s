.setcpu "65816"
.segment "CODE"
.org $7B2E
map_control_0f7b2e:
    .byte $D3 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
