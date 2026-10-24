.setcpu "65816"
.segment "CODE"
.org $28ED
map_control_0d28ed:
    .byte $F1 ; progressive-copy count
    .byte $DB ; same-value copy count/distance
