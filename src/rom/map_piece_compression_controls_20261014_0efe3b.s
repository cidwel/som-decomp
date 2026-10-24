.setcpu "65816"
.segment "CODE"
.org $FE3B
map_control_0efe3b:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
