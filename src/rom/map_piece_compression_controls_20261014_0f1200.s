.setcpu "65816"
.segment "CODE"
.org $1200
map_control_0f1200:
    .byte $DF ; same-value copy count/distance
