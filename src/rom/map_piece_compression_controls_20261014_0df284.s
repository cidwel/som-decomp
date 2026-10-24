.setcpu "65816"
.segment "CODE"
.org $F284
map_control_0df284:
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
