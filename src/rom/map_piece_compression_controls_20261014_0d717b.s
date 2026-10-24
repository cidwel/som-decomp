.setcpu "65816"
.segment "CODE"
.org $717B
map_control_0d717b:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
