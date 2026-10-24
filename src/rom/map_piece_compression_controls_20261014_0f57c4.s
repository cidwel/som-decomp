.setcpu "65816"
.segment "CODE"
.org $57C4
map_control_0f57c4:
    .byte $DF ; same-value copy count/distance
    .byte $C6 ; same-value copy count/distance
