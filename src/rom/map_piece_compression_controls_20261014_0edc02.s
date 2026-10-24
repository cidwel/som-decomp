.setcpu "65816"
.segment "CODE"
.org $DC02
map_control_0edc02:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
