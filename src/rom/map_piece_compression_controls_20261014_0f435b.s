.setcpu "65816"
.segment "CODE"
.org $435B
map_control_0f435b:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
