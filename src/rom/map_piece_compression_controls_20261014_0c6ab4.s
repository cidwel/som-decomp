.setcpu "65816"
.segment "CODE"
.org $6AB4
map_control_0c6ab4:
    .byte $F1 ; progressive-copy count
    .byte $DB ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
