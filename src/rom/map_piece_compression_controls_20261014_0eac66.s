.setcpu "65816"
.segment "CODE"
.org $AC66
map_control_0eac66:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
