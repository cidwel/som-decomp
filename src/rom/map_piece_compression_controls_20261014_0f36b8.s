.setcpu "65816"
.segment "CODE"
.org $36B8
map_control_0f36b8:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
