.setcpu "65816"
.segment "CODE"
.org $7B80
map_control_0c7b80:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
