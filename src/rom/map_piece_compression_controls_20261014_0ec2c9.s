.setcpu "65816"
.segment "CODE"
.org $C2C9
map_control_0ec2c9:
    .byte $E0 ; previous-row copy escape
    .byte $98 ; row-distance/count
