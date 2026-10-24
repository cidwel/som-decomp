.setcpu "65816"
.segment "CODE"
.org $E33D
map_control_0fe33d:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
