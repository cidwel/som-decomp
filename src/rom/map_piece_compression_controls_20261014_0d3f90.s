.setcpu "65816"
.segment "CODE"
.org $3F90
map_control_0d3f90:
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
