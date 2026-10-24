.setcpu "65816"
.segment "CODE"
.org $7B75
map_control_0c7b75:
    .byte $E0 ; previous-row copy escape
    .byte $45 ; row-distance/count
