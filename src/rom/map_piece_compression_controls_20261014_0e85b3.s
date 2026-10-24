.setcpu "65816"
.segment "CODE"
.org $85B3
map_control_0e85b3:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
