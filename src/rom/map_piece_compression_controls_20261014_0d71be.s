.setcpu "65816"
.segment "CODE"
.org $71BE
map_control_0d71be:
    .byte $CD ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
