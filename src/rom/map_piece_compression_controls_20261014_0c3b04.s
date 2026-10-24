.setcpu "65816"
.segment "CODE"
.org $3B04
map_control_0c3b04:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
