.setcpu "65816"
.segment "CODE"
.org $79DE
map_control_0c79de:
    .byte $E3 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
