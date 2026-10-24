.setcpu "65816"
.segment "CODE"
.org $C2C5
map_control_0ec2c5:
    .byte $E0 ; previous-row copy escape
    .byte $9E ; row-distance/count
    .byte $C5 ; same-value copy count/distance
