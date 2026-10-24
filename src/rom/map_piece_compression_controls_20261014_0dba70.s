.setcpu "65816"
.segment "CODE"
.org $BA70
map_control_0dba70:
    .byte $CB ; same-value copy count/distance
