.setcpu "65816"
.segment "CODE"
.org $A182
map_control_0ea182:
    .byte $DF ; same-value copy count/distance
    .byte $C3 ; same-value copy count/distance
