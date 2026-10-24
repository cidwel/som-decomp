.setcpu "65816"
.segment "CODE"
.org $E930
map_control_0de930:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
