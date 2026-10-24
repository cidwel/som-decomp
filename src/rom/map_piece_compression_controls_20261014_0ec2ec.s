.setcpu "65816"
.segment "CODE"
.org $C2EC
map_control_0ec2ec:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
