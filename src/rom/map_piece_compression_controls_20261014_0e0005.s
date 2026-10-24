.setcpu "65816"
.segment "CODE"
.org $0005
map_control_0e0005:
    .byte $E5 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
