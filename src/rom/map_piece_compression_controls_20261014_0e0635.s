.setcpu "65816"
.segment "CODE"
.org $0635
map_control_0e0635:
    .byte $DB ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
