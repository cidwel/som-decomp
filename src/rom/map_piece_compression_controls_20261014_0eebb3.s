.setcpu "65816"
.segment "CODE"
.org $EBB3
map_control_0eebb3:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
