.setcpu "65816"
.segment "CODE"
.org $0CCF
map_control_0f0ccf:
    .byte $C1 ; same-value copy count/distance
