.setcpu "65816"
.segment "CODE"
.org $E925
map_control_0de925:
    .byte $C7 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
