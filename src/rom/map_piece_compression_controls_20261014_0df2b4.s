.setcpu "65816"
.segment "CODE"
.org $F2B4
map_control_0df2b4:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
