.setcpu "65816"
.segment "CODE"
.org $5FFA
map_control_0f5ffa:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
