.setcpu "65816"
.segment "CODE"
.org $CABA
map_control_0ecaba:
    .byte $C9 ; same-value copy count/distance
