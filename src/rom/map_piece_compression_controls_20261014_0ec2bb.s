.setcpu "65816"
.segment "CODE"
.org $C2BB
map_control_0ec2bb:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
