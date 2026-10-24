.setcpu "65816"
.segment "CODE"
.org $2EAA
map_control_0c2eaa:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
