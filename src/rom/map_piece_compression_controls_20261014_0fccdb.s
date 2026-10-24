.setcpu "65816"
.segment "CODE"
.org $CCDB
map_control_0fccdb:
    .byte $C1 ; same-value copy count/distance
