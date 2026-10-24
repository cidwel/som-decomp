.setcpu "65816"
.segment "CODE"
.org $2E01
map_control_0d2e01:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
