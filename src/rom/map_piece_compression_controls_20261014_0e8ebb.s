.setcpu "65816"
.segment "CODE"
.org $8EBB
map_control_0e8ebb:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
