.setcpu "65816"
.segment "CODE"
.org $DF7B
map_control_0ddf7b:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
