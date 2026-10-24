.setcpu "65816"
.segment "CODE"
.org $45FF
map_control_0f45ff:
    .byte $CB ; same-value copy count/distance
