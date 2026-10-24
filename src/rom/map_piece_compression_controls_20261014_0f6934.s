.setcpu "65816"
.segment "CODE"
.org $6934
map_control_0f6934:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
