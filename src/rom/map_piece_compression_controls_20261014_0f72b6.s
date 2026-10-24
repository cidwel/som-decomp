.setcpu "65816"
.segment "CODE"
.org $72B6
map_control_0f72b6:
    .byte $F1 ; progressive-copy count
    .byte $DC ; same-value copy count/distance
