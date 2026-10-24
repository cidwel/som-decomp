.setcpu "65816"
.segment "CODE"
.org $35EA
map_control_0f35ea:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
