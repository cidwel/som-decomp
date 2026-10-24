.setcpu "65816"
.segment "CODE"
.org $5000
map_control_0e5000:
    .byte $C4 ; same-value copy count/distance
