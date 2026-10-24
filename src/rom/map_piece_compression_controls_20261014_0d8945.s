.setcpu "65816"
.segment "CODE"
.org $8945
map_control_0d8945:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
