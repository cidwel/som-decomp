.setcpu "65816"
.segment "CODE"
.org $7A60
map_control_0f7a60:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
