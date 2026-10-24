.setcpu "65816"
.segment "CODE"
.org $4F98
map_control_0d4f98:
    .byte $D7 ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
