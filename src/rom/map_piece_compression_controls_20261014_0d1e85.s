.setcpu "65816"
.segment "CODE"
.org $1E85
map_control_0d1e85:
    .byte $C1 ; same-value copy count/distance
    .byte $D9 ; same-value copy count/distance
