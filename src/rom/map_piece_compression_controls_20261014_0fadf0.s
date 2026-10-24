.setcpu "65816"
.segment "CODE"
.org $ADF0
map_control_0fadf0:
    .byte $E0 ; previous-row copy escape
    .byte $AA ; row-distance/count
