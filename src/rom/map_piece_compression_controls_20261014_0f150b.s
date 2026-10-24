.setcpu "65816"
.segment "CODE"
.org $150B
map_control_0f150b:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
