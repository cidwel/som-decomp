.setcpu "65816"
.segment "CODE"
.org $66DB
map_control_0c66db:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
