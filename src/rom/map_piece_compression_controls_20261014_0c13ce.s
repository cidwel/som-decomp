.setcpu "65816"
.segment "CODE"
.org $13CE
map_control_0c13ce:
    .byte $E6 ; previous-row copy count
    .byte $CC ; same-value copy count/distance
