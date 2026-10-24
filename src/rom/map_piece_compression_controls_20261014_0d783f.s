.setcpu "65816"
.segment "CODE"
.org $783F
map_control_0d783f:
    .byte $E0 ; previous-row copy escape
    .byte $46 ; row-distance/count
