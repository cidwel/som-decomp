.setcpu "65816"
.segment "CODE"
.org $4F99
map_control_0f4f99:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
