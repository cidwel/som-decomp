.setcpu "65816"
.segment "CODE"
.org $6C6A
map_control_0e6c6a:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
