.setcpu "65816"
.segment "CODE"
.org $C1A8
map_control_0dc1a8:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
