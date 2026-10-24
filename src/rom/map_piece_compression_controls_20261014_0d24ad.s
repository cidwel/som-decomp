.setcpu "65816"
.segment "CODE"
.org $24AD
map_control_0d24ad:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
