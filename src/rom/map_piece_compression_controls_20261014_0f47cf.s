.setcpu "65816"
.segment "CODE"
.org $47CF
map_control_0f47cf:
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $4F ; row-distance/count
