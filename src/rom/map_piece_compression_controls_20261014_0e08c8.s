.setcpu "65816"
.segment "CODE"
.org $08C8
map_control_0e08c8:
    .byte $F1 ; progressive-copy count
    .byte $DB ; same-value copy count/distance
