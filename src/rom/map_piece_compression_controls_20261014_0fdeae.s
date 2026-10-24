.setcpu "65816"
.segment "CODE"
.org $DEAE
map_control_0fdeae:
    .byte $C4 ; same-value copy count/distance
