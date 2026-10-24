.setcpu "65816"
.segment "CODE"
.org $1801
map_control_0f1801:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
