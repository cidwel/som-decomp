.setcpu "65816"
.segment "CODE"
.org $2705
map_control_0d2705:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
