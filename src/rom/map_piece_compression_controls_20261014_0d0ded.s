.setcpu "65816"
.segment "CODE"
.org $0DED
map_control_0d0ded:
    .byte $C1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
