.setcpu "65816"
.segment "CODE"
.org $E329
map_control_0fe329:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
