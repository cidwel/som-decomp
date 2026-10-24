.setcpu "65816"
.segment "CODE"
.org $C2F4
map_control_0ec2f4:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
    .byte $C1 ; same-value copy count/distance
