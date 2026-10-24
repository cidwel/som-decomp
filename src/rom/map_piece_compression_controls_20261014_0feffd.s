.setcpu "65816"
.segment "CODE"
.org $EFFD
map_control_0feffd:
    .byte $C4 ; same-value copy count/distance
