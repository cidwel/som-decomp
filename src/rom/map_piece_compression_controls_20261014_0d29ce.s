.setcpu "65816"
.segment "CODE"
.org $29CE
map_control_0d29ce:
    .byte $E1 ; previous-row copy count
    .byte $CC ; same-value copy count/distance
