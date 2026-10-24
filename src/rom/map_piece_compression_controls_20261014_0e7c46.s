.setcpu "65816"
.segment "CODE"
.org $7C46
map_control_0e7c46:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
