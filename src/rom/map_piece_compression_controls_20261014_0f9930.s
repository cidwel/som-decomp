.setcpu "65816"
.segment "CODE"
.org $9930
map_control_0f9930:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
