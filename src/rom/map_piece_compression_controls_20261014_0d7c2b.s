.setcpu "65816"
.segment "CODE"
.org $7C2B
map_control_0d7c2b:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
