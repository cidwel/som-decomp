.setcpu "65816"
.segment "CODE"
.org $4EAF
map_control_0f4eaf:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
