.setcpu "65816"
.segment "CODE"
.org $900C
map_control_0e900c:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
