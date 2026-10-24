.setcpu "65816"
.segment "CODE"
.org $9BFA
map_control_0e9bfa:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
