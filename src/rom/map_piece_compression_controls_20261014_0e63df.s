.setcpu "65816"
.segment "CODE"
.org $63DF
map_control_0e63df:
    .byte $C1 ; same-value copy count/distance
    .byte $DA ; same-value copy count/distance
