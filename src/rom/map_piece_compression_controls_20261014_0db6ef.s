.setcpu "65816"
.segment "CODE"
.org $B6EF
map_control_0db6ef:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
