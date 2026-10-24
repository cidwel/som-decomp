.setcpu "65816"
.segment "CODE"
.org $DFBA
map_control_0fdfba:
    .byte $C1 ; same-value copy count/distance
