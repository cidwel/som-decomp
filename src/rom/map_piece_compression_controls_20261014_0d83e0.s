.setcpu "65816"
.segment "CODE"
.org $83E0
map_control_0d83e0:
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
