.setcpu "65816"
.segment "CODE"
.org $AF76
map_control_0daf76:
    .byte $C4 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
