.setcpu "65816"
.segment "CODE"
.org $AF24
map_control_0faf24:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
