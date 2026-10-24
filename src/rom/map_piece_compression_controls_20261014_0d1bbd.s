.setcpu "65816"
.segment "CODE"
.org $1BBD
map_control_0d1bbd:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
