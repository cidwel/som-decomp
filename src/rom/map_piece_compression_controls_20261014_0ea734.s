.setcpu "65816"
.segment "CODE"
.org $A734
map_control_0ea734:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
