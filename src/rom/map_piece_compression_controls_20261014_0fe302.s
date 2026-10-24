.setcpu "65816"
.segment "CODE"
.org $E302
map_control_0fe302:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
