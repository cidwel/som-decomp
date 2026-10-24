.setcpu "65816"
.segment "CODE"
.org $DBEA
map_control_0fdbea:
    .byte $C1 ; same-value copy count/distance
