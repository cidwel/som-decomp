.setcpu "65816"
.segment "CODE"
.org $7EEF
map_control_0d7eef:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
