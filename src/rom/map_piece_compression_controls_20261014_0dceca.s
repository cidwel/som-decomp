.setcpu "65816"
.segment "CODE"
.org $CECA
map_control_0dceca:
    .byte $C2 ; same-value copy count/distance
