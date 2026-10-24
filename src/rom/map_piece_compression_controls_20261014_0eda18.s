.setcpu "65816"
.segment "CODE"
.org $DA18
map_control_0eda18:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
