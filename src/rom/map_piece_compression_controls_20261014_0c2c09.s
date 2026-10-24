.setcpu "65816"
.segment "CODE"
.org $2C09
map_control_0c2c09:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
