.setcpu "65816"
.segment "CODE"
.org $0C92
map_control_0e0c92:
    .byte $E1 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
