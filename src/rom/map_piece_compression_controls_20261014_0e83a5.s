.setcpu "65816"
.segment "CODE"
.org $83A5
map_control_0e83a5:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
