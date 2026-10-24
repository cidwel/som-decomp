.setcpu "65816"
.segment "CODE"
.org $352F
map_control_0c352f:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
