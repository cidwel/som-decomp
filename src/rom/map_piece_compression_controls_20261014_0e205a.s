.setcpu "65816"
.segment "CODE"
.org $205A
map_control_0e205a:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
