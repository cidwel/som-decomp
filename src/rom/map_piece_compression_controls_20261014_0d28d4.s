.setcpu "65816"
.segment "CODE"
.org $28D4
map_control_0d28d4:
    .byte $F1 ; progressive-copy count
    .byte $DE ; same-value copy count/distance
