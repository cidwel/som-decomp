.setcpu "65816"
.segment "CODE"
.org $8E90
map_control_0f8e90:
    .byte $CC ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
