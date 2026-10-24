.setcpu "65816"
.segment "CODE"
.org $7EAE
map_control_0d7eae:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
