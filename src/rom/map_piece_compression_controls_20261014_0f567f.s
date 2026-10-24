.setcpu "65816"
.segment "CODE"
.org $567F
map_control_0f567f:
    .byte $DB ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
