.setcpu "65816"
.segment "CODE"
.org $518D
map_control_0f518d:
    .byte $C2 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
