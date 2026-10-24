.setcpu "65816"
.segment "CODE"
.org $889A
map_control_0f889a:
    .byte $C3 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
