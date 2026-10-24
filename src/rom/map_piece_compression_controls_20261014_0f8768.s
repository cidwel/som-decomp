.setcpu "65816"
.segment "CODE"
.org $8768
map_control_0f8768:
    .byte $E5 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
