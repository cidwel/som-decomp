.setcpu "65816"
.segment "CODE"
.org $8157
map_control_0f8157:
    .byte $E4 ; previous-row copy count
    .byte $CB ; same-value copy count/distance
