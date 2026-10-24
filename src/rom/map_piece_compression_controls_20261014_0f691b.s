.setcpu "65816"
.segment "CODE"
.org $691B
map_control_0f691b:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
