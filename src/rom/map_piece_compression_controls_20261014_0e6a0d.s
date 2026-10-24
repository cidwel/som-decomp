.setcpu "65816"
.segment "CODE"
.org $6A0D
map_control_0e6a0d:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
