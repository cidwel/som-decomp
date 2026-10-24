.setcpu "65816"
.segment "CODE"
.org $C2B5
map_control_0ec2b5:
    .byte $E0 ; previous-row copy escape
    .byte $9D ; row-distance/count
    .byte $C3 ; same-value copy count/distance
