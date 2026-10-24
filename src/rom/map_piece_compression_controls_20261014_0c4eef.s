.setcpu "65816"
.segment "CODE"
.org $4EEF
map_control_0c4eef:
    .byte $D7 ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
