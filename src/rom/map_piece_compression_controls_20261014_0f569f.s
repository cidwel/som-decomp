.setcpu "65816"
.segment "CODE"
.org $569F
map_control_0f569f:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
