.setcpu "65816"
.segment "CODE"
.org $9337
map_control_0f9337:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
