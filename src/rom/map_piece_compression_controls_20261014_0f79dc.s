.setcpu "65816"
.segment "CODE"
.org $79DC
map_control_0f79dc:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
