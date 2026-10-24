.setcpu "65816"
.segment "CODE"
.org $F6A0
map_control_0ef6a0:
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
