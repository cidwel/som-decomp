.setcpu "65816"
.segment "CODE"
.org $F55B
map_control_0df55b:
    .byte $DF ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
