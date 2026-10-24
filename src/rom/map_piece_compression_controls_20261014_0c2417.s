.setcpu "65816"
.segment "CODE"
.org $2417
map_control_0c2417:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
