.setcpu "65816"
.segment "CODE"
.org $C2DA
map_control_0ec2da:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
