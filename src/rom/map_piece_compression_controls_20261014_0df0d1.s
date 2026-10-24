.setcpu "65816"
.segment "CODE"
.org $F0D1
map_control_0df0d1:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
