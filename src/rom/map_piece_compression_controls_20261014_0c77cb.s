.setcpu "65816"
.segment "CODE"
.org $77CB
map_control_0c77cb:
    .byte $E0 ; previous-row copy escape
    .byte $43 ; row-distance/count
