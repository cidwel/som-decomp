.setcpu "65816"
.segment "CODE"
.org $99FF
map_control_0d99ff:
    .byte $CB ; same-value copy count/distance
