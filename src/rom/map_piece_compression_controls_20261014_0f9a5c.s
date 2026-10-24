.setcpu "65816"
.segment "CODE"
.org $9A5C
map_control_0f9a5c:
    .byte $F1 ; progressive-copy count
    .byte $DB ; same-value copy count/distance
