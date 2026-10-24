.setcpu "65816"
.segment "CODE"
.org $C2B0
map_control_0ec2b0:
    .byte $E0 ; previous-row copy escape
    .byte $9C ; row-distance/count
    .byte $E2 ; previous-row copy count
