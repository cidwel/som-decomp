.setcpu "65816"
.segment "CODE"
.org $AE94
map_control_0eae94:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
