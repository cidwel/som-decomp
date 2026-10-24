.setcpu "65816"
.segment "CODE"
.org $420F
map_control_0f420f:
    .byte $C1 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
