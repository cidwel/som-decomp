.setcpu "65816"
.segment "CODE"
.org $A179
map_control_0ea179:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
