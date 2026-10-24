.setcpu "65816"
.segment "CODE"
.org $FB40
map_control_0ffb40:
    .byte $D1 ; same-value copy count/distance
