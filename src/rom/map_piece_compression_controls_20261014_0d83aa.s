.setcpu "65816"
.segment "CODE"
.org $83AA
map_control_0d83aa:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
