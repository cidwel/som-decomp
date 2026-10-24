.setcpu "65816"
.segment "CODE"
.org $3CD0
map_control_0f3cd0:
    .byte $C1 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
