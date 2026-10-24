.setcpu "65816"
.segment "CODE"
.org $D681
map_control_0fd681:
    .byte $C2 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
