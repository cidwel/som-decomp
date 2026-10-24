.setcpu "65816"
.segment "CODE"
.org $CCFD
map_control_0fccfd:
    .byte $C9 ; same-value copy count/distance
