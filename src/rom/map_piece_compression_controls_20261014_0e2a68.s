.setcpu "65816"
.segment "CODE"
.org $2A68
map_control_0e2a68:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
