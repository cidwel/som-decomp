.setcpu "65816"
.segment "CODE"
.org $B213
map_control_0fb213:
    .byte $C1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
