.setcpu "65816"
.segment "CODE"
.org $6982
map_control_0f6982:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
