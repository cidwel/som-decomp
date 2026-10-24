.setcpu "65816"
.segment "CODE"
.org $98CC
map_control_0f98cc:
    .byte $CB ; same-value copy count/distance
