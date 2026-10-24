.setcpu "65816"
.segment "CODE"
.org $C2C2
map_control_0ec2c2:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
