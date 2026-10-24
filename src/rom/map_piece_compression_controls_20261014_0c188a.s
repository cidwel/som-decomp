.setcpu "65816"
.segment "CODE"
.org $188A
map_control_0c188a:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
