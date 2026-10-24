.setcpu "65816"
.segment "CODE"
.org $D00D
map_control_0fd00d:
    .byte $CB ; same-value copy count/distance
