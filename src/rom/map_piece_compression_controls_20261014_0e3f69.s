.setcpu "65816"
.segment "CODE"
.org $3F69
map_control_0e3f69:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
