.setcpu "65816"
.segment "CODE"
.org $2938
map_control_0f2938:
    .byte $E3 ; previous-row copy count
    .byte $DE ; same-value copy count/distance
