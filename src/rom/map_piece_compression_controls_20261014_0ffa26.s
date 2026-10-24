.setcpu "65816"
.segment "CODE"
.org $FA26
map_control_0ffa26:
    .byte $C2 ; same-value copy count/distance
