.setcpu "65816"
.segment "CODE"
.org $3E80
map_control_0f3e80:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
