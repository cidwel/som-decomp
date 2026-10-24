.setcpu "65816"
.segment "CODE"
.org $0D55
map_control_0e0d55:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
