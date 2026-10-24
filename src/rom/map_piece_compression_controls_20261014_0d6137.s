.setcpu "65816"
.segment "CODE"
.org $6137
map_control_0d6137:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
