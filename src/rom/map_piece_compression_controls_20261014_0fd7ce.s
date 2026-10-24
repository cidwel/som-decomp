.setcpu "65816"
.segment "CODE"
.org $D7CE
map_control_0fd7ce:
    .byte $D7 ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
