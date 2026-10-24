.setcpu "65816"
.segment "CODE"
.org $5D7B
map_control_0c5d7b:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
