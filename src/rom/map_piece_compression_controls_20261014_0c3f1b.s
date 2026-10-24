.setcpu "65816"
.segment "CODE"
.org $3F1B
map_control_0c3f1b:
    .byte $CD ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
