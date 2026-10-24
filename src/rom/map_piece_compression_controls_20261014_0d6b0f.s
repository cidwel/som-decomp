.setcpu "65816"
.segment "CODE"
.org $6B0F
map_control_0d6b0f:
    .byte $F1 ; progressive-copy count
    .byte $DB ; same-value copy count/distance
