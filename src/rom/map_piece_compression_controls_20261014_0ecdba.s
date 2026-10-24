.setcpu "65816"
.segment "CODE"
.org $CDBA
map_control_0ecdba:
    .byte $CA ; same-value copy count/distance
