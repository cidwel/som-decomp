.setcpu "65816"
.segment "CODE"
.org $DFCA
map_control_0fdfca:
    .byte $D3 ; same-value copy count/distance
