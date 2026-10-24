.setcpu "65816"
.segment "CODE"
.org $36CC
map_control_0f36cc:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
