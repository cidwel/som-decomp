.setcpu "65816"
.segment "CODE"
.org $8474
map_control_0d8474:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
