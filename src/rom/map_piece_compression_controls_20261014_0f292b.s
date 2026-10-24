.setcpu "65816"
.segment "CODE"
.org $292B
map_control_0f292b:
    .byte $C1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
