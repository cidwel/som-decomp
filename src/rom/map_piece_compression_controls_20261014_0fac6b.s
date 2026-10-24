.setcpu "65816"
.segment "CODE"
.org $AC6B
map_control_0fac6b:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
