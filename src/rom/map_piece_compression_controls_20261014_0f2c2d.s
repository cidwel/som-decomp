.setcpu "65816"
.segment "CODE"
.org $2C2D
map_control_0f2c2d:
    .byte $F1 ; progressive-copy count
    .byte $DB ; same-value copy count/distance
