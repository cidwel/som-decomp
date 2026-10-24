.setcpu "65816"
.segment "CODE"
.org $9C74
map_control_0f9c74:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
    .byte $C7 ; same-value copy count/distance
