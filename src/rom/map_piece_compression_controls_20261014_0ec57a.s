.setcpu "65816"
.segment "CODE"
.org $C57A
map_control_0ec57a:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
