.setcpu "65816"
.segment "CODE"
.org $C873
map_control_0dc873:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
