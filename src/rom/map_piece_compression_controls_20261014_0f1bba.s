.setcpu "65816"
.segment "CODE"
.org $1BBA
map_control_0f1bba:
    .byte $C1 ; same-value copy count/distance
