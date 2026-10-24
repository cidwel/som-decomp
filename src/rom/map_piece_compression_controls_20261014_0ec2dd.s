.setcpu "65816"
.segment "CODE"
.org $C2DD
map_control_0ec2dd:
    .byte $E0 ; previous-row copy escape
    .byte $9A ; row-distance/count
    .byte $C2 ; same-value copy count/distance
