.setcpu "65816"
.segment "CODE"
.org $7B89
map_control_0c7b89:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
