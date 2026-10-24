.setcpu "65816"
.segment "CODE"
.org $D05E
map_control_0fd05e:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
