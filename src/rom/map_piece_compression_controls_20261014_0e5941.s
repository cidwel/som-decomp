.setcpu "65816"
.segment "CODE"
.org $5941
map_control_0e5941:
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
