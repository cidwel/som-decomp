.setcpu "65816"
.segment "CODE"
.org $7DC1
map_control_0f7dc1:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
