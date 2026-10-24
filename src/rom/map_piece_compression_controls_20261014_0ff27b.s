.setcpu "65816"
.segment "CODE"
.org $F27B
map_control_0ff27b:
    .byte $C1 ; same-value copy count/distance
