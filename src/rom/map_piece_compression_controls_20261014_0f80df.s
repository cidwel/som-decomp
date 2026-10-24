.setcpu "65816"
.segment "CODE"
.org $80DF
map_control_0f80df:
    .byte $C9 ; same-value copy count/distance
