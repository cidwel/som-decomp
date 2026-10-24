.setcpu "65816"
.segment "CODE"
.org $132E
map_control_0e132e:
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
