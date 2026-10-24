.setcpu "65816"
.segment "CODE"
.org $D354
map_control_0ed354:
    .byte $DC ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
