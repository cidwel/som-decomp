.setcpu "65816"
.segment "CODE"
.org $3146
map_control_0f3146:
    .byte $F1 ; progressive-copy count
    .byte $C9 ; same-value copy count/distance
