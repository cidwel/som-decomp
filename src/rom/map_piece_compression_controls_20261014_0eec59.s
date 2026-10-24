.setcpu "65816"
.segment "CODE"
.org $EC59
map_control_0eec59:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
