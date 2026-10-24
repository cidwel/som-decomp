.setcpu "65816"
.segment "CODE"
.org $7809
map_control_0f7809:
    .byte $D1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $8E ; distance low bit/count
