.setcpu "65816"
.segment "CODE"
.org $3692
map_control_0f3692:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
