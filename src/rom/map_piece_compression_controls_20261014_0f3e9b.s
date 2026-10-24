.setcpu "65816"
.segment "CODE"
.org $3E9B
map_control_0f3e9b:
    .byte $DF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $4E ; distance low bit/count
