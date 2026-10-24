.setcpu "65816"
.segment "CODE"
.org $2EEA
map_control_0f2eea:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
