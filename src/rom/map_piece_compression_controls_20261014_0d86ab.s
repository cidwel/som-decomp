.setcpu "65816"
.segment "CODE"
.org $86AB
map_control_0d86ab:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
