.setcpu "65816"
.segment "CODE"
.org $9FA5
map_control_0f9fa5:
    .byte $E3 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
