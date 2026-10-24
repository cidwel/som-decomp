.setcpu "65816"
.segment "CODE"
.org $36C2
map_control_0d36c2:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
