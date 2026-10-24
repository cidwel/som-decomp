.setcpu "65816"
.segment "CODE"
.org $6D92
map_control_0c6d92:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
