.setcpu "65816"
.segment "CODE"
.org $72CA
map_control_0c72ca:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
