.setcpu "65816"
.segment "CODE"
.org $09A1
map_control_0e09a1:
    .byte $DB ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
