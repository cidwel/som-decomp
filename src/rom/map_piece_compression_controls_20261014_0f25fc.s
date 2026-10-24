.setcpu "65816"
.segment "CODE"
.org $25FC
map_control_0f25fc:
    .byte $C2 ; same-value copy count/distance
