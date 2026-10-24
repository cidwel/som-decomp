.setcpu "65816"
.segment "CODE"
.org $386B
map_control_0f386b:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
