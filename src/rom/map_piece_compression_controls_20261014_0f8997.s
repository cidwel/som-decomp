.setcpu "65816"
.segment "CODE"
.org $8997
map_control_0f8997:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
