.setcpu "65816"
.segment "CODE"
.org $EFFC
map_control_0deffc:
    .byte $CF ; same-value copy count/distance
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
