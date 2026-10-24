.setcpu "65816"
.segment "CODE"
.org $1FCC
map_control_0f1fcc:
    .byte $C1 ; same-value copy count/distance
