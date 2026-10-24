.setcpu "65816"
.segment "CODE"
.org $6EEF
map_control_0d6eef:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
