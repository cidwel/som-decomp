.setcpu "65816"
.segment "CODE"
.org $7B52
map_control_0d7b52:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
