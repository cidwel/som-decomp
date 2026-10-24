.setcpu "65816"
.segment "CODE"
.org $713E
map_control_0f713e:
    .byte $F1 ; progressive-copy count
    .byte $DC ; same-value copy count/distance
