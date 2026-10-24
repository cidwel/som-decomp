.setcpu "65816"
.segment "CODE"
.org $6C13
map_control_0e6c13:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
