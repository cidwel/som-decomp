.setcpu "65816"
.segment "CODE"
.org $5846
map_control_0e5846:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
