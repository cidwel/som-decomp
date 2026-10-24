.setcpu "65816"
.segment "CODE"
.org $77E1
map_control_0d77e1:
    .byte $D9 ; same-value copy count/distance
    .byte $D1 ; same-value copy count/distance
