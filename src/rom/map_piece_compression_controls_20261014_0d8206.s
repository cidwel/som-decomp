.setcpu "65816"
.segment "CODE"
.org $8206
map_control_0d8206:
    .byte $E0 ; previous-row copy escape
    .byte $4E ; row-distance/count
