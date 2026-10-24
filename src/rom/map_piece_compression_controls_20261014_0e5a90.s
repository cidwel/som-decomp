.setcpu "65816"
.segment "CODE"
.org $5A90
map_control_0e5a90:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
