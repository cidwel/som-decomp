.setcpu "65816"
.segment "CODE"
.org $B048
map_control_0db048:
    .byte $CF ; same-value copy count/distance
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
