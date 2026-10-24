.setcpu "65816"
.segment "CODE"
.org $0708
map_control_0e0708:
    .byte $F1 ; progressive-copy count
    .byte $DB ; same-value copy count/distance
