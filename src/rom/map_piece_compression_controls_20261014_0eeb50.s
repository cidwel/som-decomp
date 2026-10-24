.setcpu "65816"
.segment "CODE"
.org $EB50
map_control_0eeb50:
    .byte $E0 ; previous-row copy escape
    .byte $9D ; row-distance/count
