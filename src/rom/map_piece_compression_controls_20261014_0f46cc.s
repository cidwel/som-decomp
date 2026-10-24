.setcpu "65816"
.segment "CODE"
.org $46CC
map_control_0f46cc:
    .byte $CB ; same-value copy count/distance
