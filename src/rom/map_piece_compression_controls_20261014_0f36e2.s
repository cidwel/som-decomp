.setcpu "65816"
.segment "CODE"
.org $36E2
map_control_0f36e2:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
