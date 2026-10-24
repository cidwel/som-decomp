.setcpu "65816"
.segment "CODE"
.org $B526
map_control_0db526:
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
