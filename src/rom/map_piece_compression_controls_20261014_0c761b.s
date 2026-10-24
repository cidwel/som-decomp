.setcpu "65816"
.segment "CODE"
.org $761B
map_control_0c761b:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
