.setcpu "65816"
.segment "CODE"
.org $77B0
map_control_0d77b0:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
