.setcpu "65816"
.segment "CODE"
.org $32FC
map_control_0d32fc:
    .byte $C6 ; same-value copy count/distance
