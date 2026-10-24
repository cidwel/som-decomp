.setcpu "65816"
.segment "CODE"
.org $AA70
map_control_0faa70:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
