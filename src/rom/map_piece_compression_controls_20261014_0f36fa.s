.setcpu "65816"
.segment "CODE"
.org $36FA
map_control_0f36fa:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
