.setcpu "65816"
.segment "CODE"
.org $FEF1
map_control_0efef1:
    .byte $E5 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
