.setcpu "65816"
.segment "CODE"
.org $AEF0
map_control_0daef0:
    .byte $E0 ; previous-row copy escape
    .byte $9A ; row-distance/count
