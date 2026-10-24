.setcpu "65816"
.segment "CODE"
.org $35D5
map_control_0f35d5:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
