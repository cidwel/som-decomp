.setcpu "65816"
.segment "CODE"
.org $FDCF
map_control_0dfdcf:
    .byte $F1 ; progressive-copy count
    .byte $DB ; same-value copy count/distance
