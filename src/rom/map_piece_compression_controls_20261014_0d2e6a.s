.setcpu "65816"
.segment "CODE"
.org $2E6A
map_control_0d2e6a:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
