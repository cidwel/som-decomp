.setcpu "65816"
.segment "CODE"
.org $28BB
map_control_0d28bb:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
