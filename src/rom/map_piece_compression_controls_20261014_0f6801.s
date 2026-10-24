.setcpu "65816"
.segment "CODE"
.org $6801
map_control_0f6801:
    .byte $C1 ; same-value copy count/distance
