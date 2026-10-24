.setcpu "65816"
.segment "CODE"
.org $081A
map_control_0f081a:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
