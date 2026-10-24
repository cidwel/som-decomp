.setcpu "65816"
.segment "CODE"
.org $BFFA
map_control_0dbffa:
    .byte $DA ; same-value copy count/distance
