.setcpu "65816"
.segment "CODE"
.org $8F78
map_control_0f8f78:
    .byte $D7 ; same-value copy count/distance
    .byte $C7 ; same-value copy count/distance
