.setcpu "65816"
.segment "CODE"
.org $C2E9
map_control_0ec2e9:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
