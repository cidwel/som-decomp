.setcpu "65816"
.segment "CODE"
.org $1F70
map_control_0e1f70:
    .byte $C1 ; same-value copy count/distance
