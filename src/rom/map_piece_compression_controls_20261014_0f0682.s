.setcpu "65816"
.segment "CODE"
.org $0682
map_control_0f0682:
    .byte $E1 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
