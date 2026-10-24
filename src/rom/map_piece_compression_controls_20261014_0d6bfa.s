.setcpu "65816"
.segment "CODE"
.org $6BFA
map_control_0d6bfa:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
