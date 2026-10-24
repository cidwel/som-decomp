.setcpu "65816"
.segment "CODE"
.org $6C50
map_control_0d6c50:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
