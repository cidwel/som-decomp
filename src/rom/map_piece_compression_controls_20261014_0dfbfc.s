.setcpu "65816"
.segment "CODE"
.org $FBFC
map_control_0dfbfc:
    .byte $C2 ; same-value copy count/distance
