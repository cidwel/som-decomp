.setcpu "65816"
.segment "CODE"
.org $AFCD
map_control_0fafcd:
    .byte $C2 ; same-value copy count/distance
