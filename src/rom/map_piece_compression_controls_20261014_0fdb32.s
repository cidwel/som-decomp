.setcpu "65816"
.segment "CODE"
.org $DB32
map_control_0fdb32:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
