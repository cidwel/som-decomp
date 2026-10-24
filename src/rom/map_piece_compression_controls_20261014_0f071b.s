.setcpu "65816"
.segment "CODE"
.org $071B
map_control_0f071b:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
