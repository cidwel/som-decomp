.setcpu "65816"
.segment "CODE"
.org $AEEF
map_control_0faeef:
    .byte $C5 ; same-value copy count/distance
