.setcpu "65816"
.segment "CODE"
.org $561D
map_control_0f561d:
    .byte $C1 ; same-value copy count/distance
    .byte $D9 ; same-value copy count/distance
