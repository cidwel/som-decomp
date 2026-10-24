.setcpu "65816"
.segment "CODE"
.org $FDE4
map_control_0dfde4:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
