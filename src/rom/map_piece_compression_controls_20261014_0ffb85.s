.setcpu "65816"
.segment "CODE"
.org $FB85
map_control_0ffb85:
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
