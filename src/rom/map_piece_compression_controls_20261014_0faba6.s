.setcpu "65816"
.segment "CODE"
.org $ABA6
map_control_0faba6:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
