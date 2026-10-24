.setcpu "65816"
.segment "CODE"
.org $D461
map_control_0fd461:
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
