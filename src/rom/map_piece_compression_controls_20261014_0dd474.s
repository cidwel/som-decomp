.setcpu "65816"
.segment "CODE"
.org $D474
map_control_0dd474:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
