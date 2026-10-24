.setcpu "65816"
.segment "CODE"
.org $8010
map_control_0f8010:
    .byte $DC ; same-value copy count/distance
