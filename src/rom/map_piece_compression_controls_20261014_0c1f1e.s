.setcpu "65816"
.segment "CODE"
.org $1F1E
map_control_0c1f1e:
    .byte $DF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
