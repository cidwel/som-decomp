.setcpu "65816"
.segment "CODE"
.org $E965
map_control_0de965:
    .byte $F1 ; progressive-copy count
    .byte $D1 ; same-value copy count/distance
