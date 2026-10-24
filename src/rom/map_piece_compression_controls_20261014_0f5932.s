.setcpu "65816"
.segment "CODE"
.org $5932
map_control_0f5932:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
