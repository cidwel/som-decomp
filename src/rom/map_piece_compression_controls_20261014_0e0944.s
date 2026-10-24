.setcpu "65816"
.segment "CODE"
.org $0944
map_control_0e0944:
    .byte $F1 ; progressive-copy count
    .byte $DC ; same-value copy count/distance
