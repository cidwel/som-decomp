.setcpu "65816"
.segment "CODE"
.org $390C
map_control_0f390c:
    .byte $CA ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
