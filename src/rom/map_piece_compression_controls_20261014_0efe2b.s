.setcpu "65816"
.segment "CODE"
.org $FE2B
map_control_0efe2b:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
