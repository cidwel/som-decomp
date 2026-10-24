.setcpu "65816"
.segment "CODE"
.org $36B2
map_control_0d36b2:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
