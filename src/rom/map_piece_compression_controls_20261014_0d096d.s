.setcpu "65816"
.segment "CODE"
.org $096D
map_control_0d096d:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
