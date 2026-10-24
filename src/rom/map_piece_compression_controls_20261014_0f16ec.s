.setcpu "65816"
.segment "CODE"
.org $16EC
map_control_0f16ec:
    .byte $C1 ; same-value copy count/distance
