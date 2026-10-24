.setcpu "65816"
.segment "CODE"
.org $0FFE
map_control_0c0ffe:
    .byte $CB ; same-value copy count/distance
