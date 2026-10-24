.setcpu "65816"
.segment "CODE"
.org $B04D
map_control_0db04d:
    .byte $CB ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
