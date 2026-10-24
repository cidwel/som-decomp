.setcpu "65816"
.segment "CODE"
.org $2026
map_control_0d2026:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
