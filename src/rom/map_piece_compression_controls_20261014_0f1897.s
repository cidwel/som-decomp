.setcpu "65816"
.segment "CODE"
.org $1897
map_control_0f1897:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
