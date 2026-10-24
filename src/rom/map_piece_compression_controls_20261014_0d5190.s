.setcpu "65816"
.segment "CODE"
.org $5190
map_control_0d5190:
    .byte $E3 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
