.setcpu "65816"
.segment "CODE"
.org $8569
map_control_0d8569:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
