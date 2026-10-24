.setcpu "65816"
.segment "CODE"
.org $7F39
map_control_0f7f39:
    .byte $E5 ; previous-row copy count
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
