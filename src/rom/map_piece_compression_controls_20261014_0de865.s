.setcpu "65816"
.segment "CODE"
.org $E865
map_control_0de865:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
