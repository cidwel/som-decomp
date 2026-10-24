.setcpu "65816"
.segment "CODE"
.org $EDF9
map_control_0dedf9:
    .byte $F1 ; progressive-copy count
    .byte $C6 ; same-value copy count/distance
