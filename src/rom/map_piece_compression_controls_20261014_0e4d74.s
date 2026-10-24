.setcpu "65816"
.segment "CODE"
.org $4D74
map_control_0e4d74:
    .byte $CF ; same-value copy count/distance
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
