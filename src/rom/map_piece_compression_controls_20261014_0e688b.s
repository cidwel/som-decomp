.setcpu "65816"
.segment "CODE"
.org $688B
map_control_0e688b:
    .byte $E4 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
