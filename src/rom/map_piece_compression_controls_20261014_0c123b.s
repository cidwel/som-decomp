.setcpu "65816"
.segment "CODE"
.org $123B
map_control_0c123b:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
