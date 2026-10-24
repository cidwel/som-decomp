.setcpu "65816"
.segment "CODE"
.org $0F1E
map_control_0f0f1e:
    .byte $C1 ; same-value copy count/distance
    .byte $D9 ; same-value copy count/distance
