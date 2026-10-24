.setcpu "65816"
.segment "CODE"
.org $49F4
map_control_0e49f4:
    .byte $DF ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
