.setcpu "65816"
.segment "CODE"
.org $7EFA
map_control_0d7efa:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
