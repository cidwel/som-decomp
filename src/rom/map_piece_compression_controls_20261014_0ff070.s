.setcpu "65816"
.segment "CODE"
.org $F070
map_control_0ff070:
    .byte $C2 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
