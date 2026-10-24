.setcpu "65816"
.segment "CODE"
.org $89A1
map_control_0f89a1:
    .byte $C1 ; same-value copy count/distance
    .byte $DE ; same-value copy count/distance
