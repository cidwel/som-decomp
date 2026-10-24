.setcpu "65816"
.segment "CODE"
.org $FC28
map_control_0ffc28:
    .byte $C2 ; same-value copy count/distance
