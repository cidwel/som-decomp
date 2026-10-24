.setcpu "65816"
.segment "CODE"
.org $FCC5
map_control_0ffcc5:
    .byte $C1 ; same-value copy count/distance
