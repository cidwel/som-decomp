.setcpu "65816"
.segment "CODE"
.org $2BCA
map_control_0d2bca:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
