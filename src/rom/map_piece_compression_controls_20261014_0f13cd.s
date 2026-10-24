.setcpu "65816"
.segment "CODE"
.org $13CD
map_control_0f13cd:
    .byte $C1 ; same-value copy count/distance
