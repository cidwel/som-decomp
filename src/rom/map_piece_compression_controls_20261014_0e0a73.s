.setcpu "65816"
.segment "CODE"
.org $0A73
map_control_0e0a73:
    .byte $F1 ; progressive-copy count
    .byte $DB ; same-value copy count/distance
