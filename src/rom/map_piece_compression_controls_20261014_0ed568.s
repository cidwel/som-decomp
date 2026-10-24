.setcpu "65816"
.segment "CODE"
.org $D568
map_control_0ed568:
    .byte $DA ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
