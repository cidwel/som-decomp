.setcpu "65816"
.segment "CODE"
.org $C786
map_control_0fc786:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
