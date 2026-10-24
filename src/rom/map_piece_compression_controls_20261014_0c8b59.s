.setcpu "65816"
.segment "CODE"
.org $8B59
map_control_0c8b59:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
