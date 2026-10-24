.setcpu "65816"
.segment "CODE"
.org $8213
map_control_0d8213:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
