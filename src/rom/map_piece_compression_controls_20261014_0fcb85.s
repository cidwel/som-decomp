.setcpu "65816"
.segment "CODE"
.org $CB85
map_control_0fcb85:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
