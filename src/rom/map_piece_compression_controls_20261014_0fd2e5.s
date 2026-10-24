.setcpu "65816"
.segment "CODE"
.org $D2E5
map_control_0fd2e5:
    .byte $C6 ; same-value copy count/distance
    .byte $F2 ; progressive-copy count
