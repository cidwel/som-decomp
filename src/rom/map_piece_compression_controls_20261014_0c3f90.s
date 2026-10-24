.setcpu "65816"
.segment "CODE"
.org $3F90
map_control_0c3f90:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $CE ; same-value copy count/distance
