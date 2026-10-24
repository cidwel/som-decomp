.setcpu "65816"
.segment "CODE"
.org $4F42
map_control_0f4f42:
    .byte $E7 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
