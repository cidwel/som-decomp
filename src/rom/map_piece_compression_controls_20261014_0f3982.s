.setcpu "65816"
.segment "CODE"
.org $3982
map_control_0f3982:
    .byte $F1 ; progressive-copy count
    .byte $DD ; same-value copy count/distance
