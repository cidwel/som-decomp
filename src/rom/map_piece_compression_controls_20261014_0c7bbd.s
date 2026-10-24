.setcpu "65816"
.segment "CODE"
.org $7BBD
map_control_0c7bbd:
    .byte $E0 ; previous-row copy escape
    .byte $4F ; row-distance/count
