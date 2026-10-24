.setcpu "65816"
.segment "CODE"
.org $C2EF
map_control_0ec2ef:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
