.setcpu "65816"
.segment "CODE"
.org $46DB
map_control_0f46db:
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
