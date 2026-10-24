.setcpu "65816"
.segment "CODE"
.org $9D4B
map_control_0e9d4b:
    .byte $D3 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
