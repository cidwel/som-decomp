.setcpu "65816"
.segment "CODE"
.org $D49B
map_control_0dd49b:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
