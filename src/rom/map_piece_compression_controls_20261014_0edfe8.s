.setcpu "65816"
.segment "CODE"
.org $DFE8
map_control_0edfe8:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
