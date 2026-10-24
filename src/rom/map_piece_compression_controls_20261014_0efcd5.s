.setcpu "65816"
.segment "CODE"
.org $FCD5
map_control_0efcd5:
    .byte $E6 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
