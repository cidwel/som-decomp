.setcpu "65816"
.segment "CODE"
.org $87CE
map_control_0e87ce:
    .byte $C2 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
