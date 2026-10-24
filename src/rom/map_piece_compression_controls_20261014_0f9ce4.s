.setcpu "65816"
.segment "CODE"
.org $9CE4
map_control_0f9ce4:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
