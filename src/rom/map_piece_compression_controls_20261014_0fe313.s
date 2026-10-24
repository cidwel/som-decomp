.setcpu "65816"
.segment "CODE"
.org $E313
map_control_0fe313:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
