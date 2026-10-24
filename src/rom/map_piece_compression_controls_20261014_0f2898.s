.setcpu "65816"
.segment "CODE"
.org $2898
map_control_0f2898:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
