.setcpu "65816"
.segment "CODE"
.org $8F99
map_control_0e8f99:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
